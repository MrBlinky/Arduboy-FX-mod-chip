#pragma once
#include <Arduino.h>

// embedded AVR ISP for Arduboy(ATMEGA32U4)

// Arduboy external setup:
// OLED and FX chip selects must be inactive high before executio any ISP functions
// SCK, MOSI (and SS/RXLED) must be configured as outputs and MISO as input

// ISP reset pin output (Arduboy)
#define ISP_RESET_PORT PORTD
#define ISP_RESET_DDR  DDRD
#define ISP_RESET_BIT  0

// ISP programming commands
#define ISP_CMD_PROGRAM_ENABLE  0xAC53  // 0xAC 0x53 0x00 0x00 Programming enable 
#define ISP_CMD_READ_ID         0x3000  // 0x30 0x00 LSB  0x00 Read device ID byte 0..2 
#define ISP_CMD_CHIP_ERASE      0xAC80  // 0xAC 0x80 0x00 0x00 chip erase 
#define ISP_CMD_POLL            0xF000  // 0xF0 0x00 0x00 Din  Poll RDY/BSY
    
#define ISP_CMD_READ_LOW_FUSE   0x5000  // 0x50 0x00 0x00 Dout Read Fuse bits
#define ISP_CMD_READ_HIGH_FUSE  0x5808  // 0x58 0x08 0x00 Dout Read Fuse High bits
#define ISP_CMD_READ_EXT_FUSE   0x5008  // 0x50 0x08 0x00 Dout Read Extended Fuse Bits
#define ISP_CMD_READ_LOCK_BITS  0x5800  // 0x58 0x00 0x00 Dout Read Lock bits
    
#define ISP_CMD_WRITE_LOW_FUSE  0xACA0  // 0xAC 0xA0 0x00 Din  Write fuse bits
#define ISP_CMD_WRITE_HIGH_FUSE 0xACA8  // 0xAC 0xA8 0x00 Din  Write high fuse bits
#define ISP_CMD_WRITE_EXT_FUSE  0xACA4  // 0xAC 0xA4 0x00 Din  Write Ext fuse bits
#define ISP_CMD_WRITE_LOCK_BITS 0xACE0  // 0xAC 0xE0 0x00 Din  Write Lock bits
    
#define ISP_CMD_READ_LO_BYTE    0x2000  // 0x20 MSB  LSB  LO   Read Program Memory, Low byte   
#define ISP_CMD_READ_HI_BYTE    0x2800  // 0x28 MSB  LSB  HI   Read Program Memory, High byte  
    
#define ISP_CMD_FLASH_LO_BYTE   0x4000  // 0x40 MSB  LSB  LOB  Load Program memory Page, Low byte
#define ISP_CMD_FLASH_HI_BYTE   0x4800  // 0x48 MSB  LSB  HIB  Load Program memory Page, High byte
#define ISP_CMD_FLASH_PAGE      0x4C00  // 0x4C MSB  LSB  0x00 Write program memory page   
                                      
#define ISP_CMD_READ_EEPROM     0xA000  // 0xA0 MSB  LSB  Dout  Read EEPROM Memory
#define ISP_CMD_WRITE_EEPROM    0xC000  // 0xC0 MSB  LSB  Din   Write EEPROM memory (a = 0..63)

// misc defines
#define ISP_HIGH_BYTE_MASK      0x08
#define ISP_EEPROM_MASK         0x80
#define ISP_EESAVE_FUSE_MASK    0x08

#define ISP_PAGE_SIZE           0x20 // Page size in program WORDs for ATTINY45/85
#define ISP_PAGE_MASK           (ISP_PAGE_SIZE - 1)

// ISP data block identifiers
#define ISP_DATA_FLASH          (ISP_CMD_FLASH_LO_BYTE >> 8)
#define ISP_DATA_EEPROM         (ISP_CMD_WRITE_EEPROM >> 8)
#define ISP_DATA_END            0x00

extern void delayMillis(uint8_t millis);

static void __attribute__((always_inline)) ISP_transfer(uint8_t data) 
{                             
  SPDR = data;                
  while(!(SPSR & _BV(SPIF))); 
}                             

uint8_t ISP_command(uint16_t command, uint8_t data);

uint8_t ISP_command(uint16_t command);

void ISP_wait();

uint8_t ISP_commandWait(uint16_t command, uint8_t data);

uint8_t ISP_commandWait(uint16_t command);

void ISP_disable();

bool ISP_enable();

void ISP_eraseChip();

void ISP_flashPage(uint16_t addr); 

void ISP_writeData(const uint8_t* data); // flash (multiple) FLASH and/or EEPROM blocks

void ISP_writeProgramFlash(const uint8_t* data);

bool ISP_verifyProgramFlash(const uint8_t* data); // verifies data at program flash
                                                  // Returns true on successful verify
                                                  
uint16_t ISP_getFlashCrc(uint16_t addr, uint16_t len); //calculate CRC16-CCITT over flash memory block
                                                  
uint8_t ISP_readLowFuse();

void ISP_writeLowFuse(uint8_t fuse);

uint8_t ISP_readHighFuse();

void ISP_writeHighFuse(uint8_t fuse);

uint8_t ISP_readExtFuse();

void ISP_writeExtFuse(uint8_t fuse);

uint8_t ISP_readLockBits();

void ISP_writeLockBits(uint8_t fuse);

void ISP_setFuse_EESAVE(); // set EESAVE fuse so EEPROM will not be erased on chip erase

void ISP_writeEEPROM_00(uint8_t data); // writes byte to EEPROM address 0

uint8_t ISP_readEEPROM_00(); // reads byte at EEPROM address 0
