#include "isp.h"

uint8_t SPCR_old; //backup of SPI configuration
uint8_t SPSR_old;

uint8_t ISP_command(uint16_t command, uint8_t data)
{
  ISP_transfer(command >> 8);
  ISP_transfer(command & 0xFF);
  uint8_t tmp = 0;
  if ((uint8_t)(command >> 8) == (uint8_t)(ISP_CMD_READ_ID >> 8))
  {
    tmp = data;
    data = 0;
  }
  ISP_transfer(tmp);
  uint8_t result = SPDR;
  ISP_transfer(data);
  if ((uint8_t)(command & 0xFF) != (uint8_t)(ISP_CMD_PROGRAM_ENABLE & 0xFF)) result = SPDR;
  return result;
}  

uint8_t ISP_command(uint16_t command)
{
  return ISP_command(command, 0);
}

void ISP_wait()
{
  while (ISP_command(ISP_CMD_POLL) & 0x01);
}

uint8_t ISP_commandWait(uint16_t command, uint8_t data)
{
  uint8_t result = ISP_command(command, data);
  while (ISP_command(ISP_CMD_POLL) & 0x01);
  return result;
}

uint8_t ISP_commandWait(uint16_t command)\
{
  return ISP_commandWait(command, 0);
}

void ISP_disable()
{
  ISP_RESET_DDR &= ~(1 << ISP_RESET_BIT); // as input
  //restore SPI
  SPCR = SPCR_old;
  SPSR = SPSR_old;
}

bool ISP_enable()
{
  uint8_t result;
  //configure SPI
  SPCR_old = SPCR; // backup old value
  SPCR = (0 << SPIE) | // no interrupts
         (1 << SPE)  | // enable
         (0 << DORD) | // MSB first
         (1 << MSTR) | // Enabe, Master mode
         (0 << CPOL) | (0 << CPHA) | // Mode 0
         (1 << SPR1) | (1 << SPR0);  // IOCLK/128 = 125KHz
  SPSR_old = SPSR;
  SPSR = (0 <<SPI2X);
  for (uint8_t retries = 0; retries < 10; retries++)
  {
    ISP_RESET_PORT |= _BV(ISP_RESET_BIT); // inactive high
    ISP_RESET_DDR  |= _BV(ISP_RESET_BIT); // as output
    delayMillis(1);
    ISP_RESET_PORT &= ~_BV(ISP_RESET_BIT); //active low
    delayMillis(20);
    result = ISP_command(ISP_CMD_PROGRAM_ENABLE);
    if (result == (uint8_t)(ISP_CMD_PROGRAM_ENABLE & 0xFF)) break; //entered programming mode successfully
  }
  if (result == (uint8_t)(ISP_CMD_PROGRAM_ENABLE & 0xFF)) return true;
  ISP_disable();
  return false;
}

void ISP_eraseChip()
{
  ISP_commandWait(ISP_CMD_CHIP_ERASE);
}

void ISP_flashPage(uint16_t addr)
{
  ISP_transfer(ISP_CMD_FLASH_PAGE >> 8);
  ISP_transfer(addr >> 8);
  ISP_transfer(addr & 0xFF);
  ISP_transfer(0);
  ISP_wait();
}

void ISP_writeData(const uint8_t* data) /* not used */
{
  uint8_t cmd  = pgm_read_byte(data++); //fetch FLASH/EEPROM write command, or End of Data
  while(cmd)
  {
    uint16_t addr = pgm_read_byte(data++) | (pgm_read_byte(data++) << 8);
    uint16_t len  = pgm_read_byte(data++) | (pgm_read_byte(data++) << 8);
    while(len)
    {
      ISP_transfer(cmd);
      ISP_transfer(addr >> 8);
      ISP_transfer(addr & 0xFF);
      ISP_transfer(pgm_read_byte(data++));
      if (!(cmd & ISP_EEPROM_MASK)) //FLASH: handle high/low byte and page write
      {
        if ((cmd & ISP_HIGH_BYTE_MASK) && ((addr & ISP_PAGE_MASK) == ISP_PAGE_MASK))
        {
          ISP_flashPage(addr);
        }
        cmd ^= ISP_HIGH_BYTE_MASK; //toggle HI byte /LO byte command
      }
      else //EEPROM: just wait
      {
        ISP_wait();
      }
      if (!(cmd & ISP_HIGH_BYTE_MASK)) //don't adjust after a lo byte flash write
      {
        addr++; 
        len--;
      }
    }
    if (!(cmd & ISP_EEPROM_MASK) && (addr & ISP_PAGE_MASK)) // flash partial last page 
    {
      ISP_flashPage(addr);
    }
    cmd  = pgm_read_byte(data++); //fetch FLASH/EEPROM write command, or End of Data
  }
}

void ISP_writeProgramFlash(const uint8_t* data)
{
  uint8_t cmd = ISP_CMD_FLASH_LO_BYTE >> 8;
  uint16_t len  = pgm_read_byte(data++) | (pgm_read_byte(data++) << 8);
  while(len)
  {
    uint16_t addr = pgm_read_byte(data++) | (pgm_read_byte(data++) << 8);
    while(len)
    {
      ISP_transfer(cmd);
      ISP_transfer(addr >> 8);
      ISP_transfer(addr & 0xFF);
      ISP_transfer(pgm_read_byte(data++));
      if ((cmd & ISP_HIGH_BYTE_MASK) && ((addr & ISP_PAGE_MASK) == ISP_PAGE_MASK))
      {
        ISP_flashPage(addr);
      }
      cmd ^= ISP_HIGH_BYTE_MASK; //toggle HI byte /LO byte command
      if (!(cmd & ISP_HIGH_BYTE_MASK)) //don't adjust after a lo byte flash write
      {
        addr++; 
        len--;
      }
    }
    if (addr & ISP_PAGE_MASK) // flash partial last page 
    {
      ISP_flashPage(addr);
    }
    len  = pgm_read_byte(data++) | (pgm_read_byte(data++) << 8);// next block length or end marker
  }
}

bool ISP_verifyProgramFlash(const uint8_t* data)
{
  uint8_t cmd = ISP_CMD_READ_LO_BYTE >> 8;
  uint16_t len  = pgm_read_byte(data++) | (pgm_read_byte(data++) << 8);
  while(len)
  {
    uint16_t addr = pgm_read_byte(data++) | (pgm_read_byte(data++) << 8);
    while(len)
    {
      ISP_transfer(cmd);
      ISP_transfer(addr >> 8);
      ISP_transfer(addr & 0xFF);
      ISP_transfer(0);
      if (pgm_read_byte(data++) != SPDR) return false;
      cmd ^= ISP_HIGH_BYTE_MASK; //toggle HI byte /LO byte command
      if (!(cmd & ISP_HIGH_BYTE_MASK)) //don't adjust after a lo byte flash write
      {
        addr++; 
        len--;
      }
    }
    len  = pgm_read_byte(data++) | (pgm_read_byte(data++) << 8);// next block length or end marker
  }
  return true;
}

uint16_t ISP_getFlashCrc(uint16_t addr, uint16_t len)
{
  uint16_t crc = 0xFFFF;
  uint8_t cmd = ISP_CMD_READ_LO_BYTE >> 8;
  while(len)
  {
    ISP_transfer(cmd);
    ISP_transfer(addr >> 8);
    ISP_transfer(addr & 0xFF);
    ISP_transfer(0);
    uint8_t data = SPDR;
    data ^= crc & 0xFF; 
    data ^= (data << 4) & 0xFF;
    crc  = ((data << 8) | (crc >> 8)) ^ (data >> 4) ^ (data << 3);
    cmd ^= ISP_HIGH_BYTE_MASK; //toggle HI byte /LO byte command
    if (!(cmd & ISP_HIGH_BYTE_MASK)) //don't adjust after a lo byte flash write
    {
      addr++; 
      len--;
    }
  }    
  return crc;
}

uint8_t ISP_readLowFuse()
{
  return ISP_command(ISP_CMD_READ_LOW_FUSE);
}

void ISP_writeLowFuse(uint8_t fuse)
{
  ISP_commandWait(ISP_CMD_WRITE_LOW_FUSE,fuse);
}

uint8_t ISP_readHighFuse()
{
  return ISP_command(ISP_CMD_READ_HIGH_FUSE);
}

void ISP_writeHighFuse(uint8_t fuse)
{
  ISP_commandWait(ISP_CMD_WRITE_HIGH_FUSE,fuse);
}

uint8_t ISP_readExtFuse()
{
  return ISP_command(ISP_CMD_READ_EXT_FUSE);
}

void ISP_writeExtFuse(uint8_t fuse)
{
  ISP_commandWait(ISP_CMD_WRITE_EXT_FUSE,fuse);
}

uint8_t ISP_readLockBits()
{
  return ISP_command(ISP_CMD_READ_LOCK_BITS);
}

void ISP_writeLockbits(uint8_t fuse)
{
  ISP_commandWait(ISP_CMD_WRITE_LOCK_BITS,fuse);
}

void ISP_setFuse_EESAVE()
{ 
  uint8_t fuse = ISP_command(ISP_CMD_READ_HIGH_FUSE);
  if (fuse & ISP_EESAVE_FUSE_MASK)
  {
    fuse &= ~ISP_EESAVE_FUSE_MASK;
    ISP_commandWait(ISP_CMD_WRITE_HIGH_FUSE,fuse);
  }
}

void ISP_writeEEPROM_00(uint8_t data)
{
  ISP_commandWait(ISP_CMD_WRITE_EEPROM, data);
}

uint8_t ISP_readEEPROM_00()
{
  return ISP_command(ISP_CMD_READ_EEPROM);
}
