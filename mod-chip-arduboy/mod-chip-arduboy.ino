/*******************************************************************************
Arduboy ModChip loader v1.03 (Arduboy part) Dec 2019 -Apr 2020 by Mr.Blinky

Arduboy program to program the modchips attiny firmware

Licenced under MIT


 ARDUBOY    |   attiny wiring       | ARDUBOY
                ____     ____               
 SCL/PD0 =>  __|RST \___/ VCC|__ VCC
               |             |
 SDA/PD1 <=  __|PB3       PB2|__ <=>  SCK 
               |   ATTINY45  |        
 RESET   <=> __|PB4       PB1|__ <=>  MISO
               |   ATTINY85  |        
 GND         __|GND       PB0|__ <=>  MOSI
               |_____________|

PD0 an active low output puts the ATTINY in ISP mode so it can be 
    programmed by Arduboy. In all other cases it is left as input 
    mode (no pullup required) so ATTINY can execute its program.
    
PD1 is FX_CS an active low selects the flash chip. PB3 is configured
    as input with pull up to so flash chip is disabled during.
    
    the ATTINY can only access the flash chip when Arduboy has put its
    SPI pins in input mode. (Can be achieved by Arduboy writing a
    special command to EEPROM, free SPI pins and then releases ATTINY
    from ISP mode.)

*******************************************************************************/

#include <Arduboy2.h>
#include "ArduboyFX.h"
#include "bitmaps.h"
#include "isp.h"
#include "mod-chip-attiny.ino.tiny8.h"
#define  FIRMWARE mod_chip_attiny_ino_tiny8

//port pin connected to FX flash chip select
#define FX_CS_PORT PORTD
#define FX_CS_DDR  DDRD
#define FX_CS_BIT  1

#ifndef EEPROM_BOOT_FLAGS
 #define EEPROM_BOOT_FLAGS 0x00
#endif

#ifndef BOOT_FLAG_POWERON_MENU_MASK
 #define BOOT_FLAG_POWERON_MENU_MASK 0x80 // Power on into FX loader menu flag
#endif

constexpr uint8_t msMain            = 0;
constexpr uint8_t msMenu            = 1;
constexpr uint8_t msArduboy         = 2;
constexpr uint8_t msModchip         = 3;
constexpr uint8_t msFlashchip       = 4;
constexpr uint8_t msHardware        = 5;
constexpr uint8_t msFlashModchip    = 6;
constexpr uint8_t msFlashBootloader = 7;

constexpr uint8_t smIdle  = 0;
constexpr uint8_t smLeft  = 1;
constexpr uint8_t smRight = 2;

Arduboy2 arduboy;
uint8_t menuState;
uint8_t menuOption;

uint8_t flashingState;

uint8_t modchipCrcState;
uint16_t modchipCrc;

JedecID jedecID;

void delayMillis(uint8_t millis) // wrapper for ISP delay
{
  arduboy.delayShort(millis);
}

void printHexByte(uint8_t n)
{
  if (n < 16) arduboy.print("0");
  arduboy.print(n,16);
}

void printHexWord(uint16_t w)
{
  printHexByte(w >> 8);
  printHexByte(w & 0xFF);
}

bool modchipFound()
{
  if (!ISP_enable()) return false;
  ISP_disable();
  return true;
}

bool flashchipFound()
{
  FX::wakeUp();
  FX::readJedecID(&jedecID);
  return jedecID.manufacturer == 0xEF;
}
/******************************************************************************/

void mainScreen()
{
  arduboy.drawBitmap(0, 0, mainScreenBitmap, mainScreenBitmapWidth, mainScreenBitmapHeight, WHITE);
  if (modchipFound()) 
    arduboy.drawBitmap(80, 43, checkBitmap, checkBitmapWidth, checkBitmapHeight, WHITE);
  else
    arduboy.drawBitmap(80, 43, crossBitmap, crossBitmapWidth, crossBitmapHeight, WHITE);
  if (flashchipFound())
    arduboy.drawBitmap(84, 53, checkBitmap, checkBitmapWidth, checkBitmapHeight, WHITE);
  else
    arduboy.drawBitmap(84, 53, crossBitmap, crossBitmapWidth, crossBitmapHeight, WHITE);
   
  if (arduboy.justPressed(A_BUTTON)) menuState = msMenu;
}
/******************************************************************************/

void flashModchip()
{
    if (flashingState == 0)
    {
      arduboy.setCursor(10,22);
      arduboy.print(F("Press    button to"));
      arduboy.setCursor(10,34);
      arduboy.print(F("Flash Mod chip"));
      arduboy.drawBitmap(46,20, buttonBitmap, buttonBitmapWidth, buttonBitmapHeight, WHITE);
      arduboy.drawBitmap(99,48, backButtonBitmap, backButtonBitmapWidth, backButtonBitmapHeight, WHITE);
      if (arduboy.justPressed(A_BUTTON)) 
        ++flashingState;
      else if (arduboy.justPressed(B_BUTTON))
        menuState = msMenu;
    }
    else if (flashingState == 1)
    {
      if (modchipFound())
      {
      arduboy.setCursor(13,28);
      arduboy.print(F("Flashing Mod chip"));
      ++flashingState;
      }
      else
        flashingState = 6;
    }
    else if (flashingState == 2)
    {
      if (ISP_enable())
      {
        ISP_eraseChip();
        ISP_writeProgramFlash(FIRMWARE);
        ISP_disable();
        modchipCrcState = 0;
        arduboy.setCursor(10,28);
        arduboy.print(F("verifying Mod chip"));
      }
        ++flashingState;
    }
    else 
    {
      if (flashingState == 3)
      {
        if (ISP_enable())
        {
          if (ISP_verifyProgramFlash(FIRMWARE)) flashingState++;
          ISP_disable();
        }
      ++flashingState;
      }
      if (flashingState == 4)
      {
        arduboy.setCursor(22,28);
        arduboy.print(F("Verify failed!"));
      }
      if (flashingState == 5) 
      {
        arduboy.setCursor(22,28);
        arduboy.print(F("Verify success"));
      }
      if (flashingState == 6) 
      {
        arduboy.setCursor(10,28);
        arduboy.print(F("Modchip not found!"));
      }
      
      if (arduboy.justPressed(A_BUTTON | B_BUTTON)) 
      {
        flashingState = 0;
        menuState = msMenu;      
      }
    }
}
/******************************************************************************/

void flashBootloader()
{
  if (flashingState == 0)
  {
    arduboy.setCursor(10,22);
    arduboy.print(F("Press    button to"));
    arduboy.setCursor(10,34);
    arduboy.print(F("Flash bootloader"));
    arduboy.drawBitmap(46,20, buttonBitmap, buttonBitmapWidth, buttonBitmapHeight, WHITE);
    arduboy.drawBitmap(99,48, backButtonBitmap, backButtonBitmapWidth, backButtonBitmapHeight, WHITE);
    if (arduboy.justPressed(A_BUTTON)) ++flashingState;
    else if (arduboy.justPressed(B_BUTTON)) menuState = msMenu;
  }
  else if (flashingState == 3)
  {
    arduboy.setCursor(7,22);
    arduboy.print(F("Flashing bootloader"));
    arduboy.setCursor(43,34);
    arduboy.print(F("Failed!"));
    if (arduboy.justPressed(A_BUTTON | B_BUTTON)) 
    {
      flashingState = 0;
      menuState = msMenu;      
    }
  }
  else
  {
    arduboy.setCursor(7,16);
    arduboy.print(F("Flashing bootloader"));
    arduboy.setCursor(7,28);
    arduboy.print(F("Arduboy will reboot"));
    arduboy.setCursor(7,40);
    arduboy.print(F("in a moment..."));
    if (flashingState == 2)
    {
      if (ISP_enable())
      {
        ISP_writeEEPROM_00(0xFB); // Flash Bootloader command
        ISP_disable();
        arduboy.delayShort(500); // wait for mod chip to kick in and reset Arduboy
      }
    }
    ++flashingState;
  }
}

/******************************************************************************/

void menuScreen()
{
  arduboy.drawBitmap(0, 0, menuScreenBitmap, menuScreenBitmapWidth, menuScreenBitmapHeight, WHITE);
  arduboy.drawBitmap(16, 11 * menuOption, selectBitmap, selectBitmapWidth, selectBitmapHeight, WHITE);

  if (arduboy.justPressed(DOWN_BUTTON)) 
    menuOption = (menuOption + 1) & 3;
  if (arduboy.justPressed(UP_BUTTON)) 
    menuOption = (menuOption - 1) & 3;
  if (arduboy.justPressed(A_BUTTON))
  {
     if (menuOption == 0)      menuState = msArduboy;
     else if (menuOption == 1) menuState = msFlashModchip;
     else if (menuOption == 2) menuState = msFlashBootloader;
  }
  if (arduboy.justPressed(B_BUTTON)) menuState = msMain;
}

/******************************************************************************/

void hardwareInfo()
{
  arduboy.setCursor(16,0);
  arduboy.print(F("HARDWARE DETAILS"));
  arduboy.drawBitmap(0,43, leftRightBitmap, leftRightBitmapWidth, leftRightBitmapHeight, WHITE);
  arduboy.drawBitmap(99,48, backButtonBitmap, backButtonBitmapWidth, backButtonBitmapHeight, WHITE);

  arduboy.setCursor(49,28);
  arduboy.print(F("TO DO"));

  if (arduboy.justPressed(LEFT_BUTTON))       menuState = msFlashchip;
  else if (arduboy.justPressed(RIGHT_BUTTON)) menuState = msArduboy;
  else if (arduboy.justPressed(B_BUTTON))     menuState = msMenu;
}

/******************************************************************************/

void flashchipInfo()
{
  arduboy.setCursor(10,0);
  arduboy.print(F("FLASH CHIP DETAILS"));
  arduboy.drawBitmap(0,43, leftRightBitmap, leftRightBitmapWidth, leftRightBitmapHeight, WHITE);
  arduboy.drawBitmap(99,48, backButtonBitmap, backButtonBitmapWidth, backButtonBitmapHeight, WHITE);

  if (flashchipFound())
  {
    arduboy.setCursor(19,22);
    arduboy.print(F("JEDEC ID:"));
    printHexByte(jedecID.manufacturer);
    printHexByte(jedecID.device);
    printHexByte(jedecID.size);
    arduboy.setCursor(25,34);
    arduboy.print(F("Size:"));
    arduboy.print (1 << (jedecID.size - 10));
    arduboy.print(F(" KB"));
  }
  else
  {
  arduboy.setCursor(1,28);
  arduboy.print(F("Flash chip not found!"));
      
  }      
  
  if (arduboy.justPressed(LEFT_BUTTON))       menuState = msModchip;
  else if (arduboy.justPressed(RIGHT_BUTTON)) menuState = msArduboy;
  else if (arduboy.justPressed(B_BUTTON))     menuState = msMenu;
}

/******************************************************************************/

uint8_t readFuses(uint8_t fuse)
{
  uint8_t oldSREG =  SREG;
  cli();
  SPMCSR = _BV(BLBSET) | _BV(SPMEN);
  fuse = pgm_read_byte(fuse);  
  SREG = oldSREG;
  return fuse;
}

void arduboyInfo()
{
  arduboy.setCursor(19,0);
  arduboy.print(F("ARDUBOY DETAILS"));
  arduboy.drawBitmap(0,43, leftRightBitmap, leftRightBitmapWidth, leftRightBitmapHeight, WHITE);
  arduboy.drawBitmap(99,48, backButtonBitmap, backButtonBitmapWidth, backButtonBitmapHeight, WHITE);
  
  arduboy.drawBitmap(2,9, buttonBitmap, buttonBitmapWidth, buttonBitmapHeight, WHITE);
  arduboy.setCursor(16,11);
  arduboy.print(F("Power-on menu:"));
  uint8_t bootflags = EEPROM.read(EEPROM_BOOT_FLAGS);
  if (bootflags & BOOT_FLAG_POWERON_MENU_MASK) arduboy.print(F("ON"));
  else arduboy.print(F("OFF"));
  
  arduboy.setCursor(16,19);
  arduboy.print(F("Lfuse:"));
  printHexByte(readFuses(0));
  arduboy.print(F(" Efuse:"));
  printHexByte(readFuses(2));
  
  arduboy.setCursor(16,27);
  uint8_t hfuse = readFuses(3);
  arduboy.print(F("Hfuse:"));
  printHexByte(hfuse);
  arduboy.print(F(" Lock: "));
  printHexByte(readFuses(1));
  
  arduboy.setCursor(16,35);
  arduboy.print(F("BootCRC:"));
  uint8_t* bootldr = 0x7000;                    // 4K bootloader
  if ((hfuse & 0x06) == 0x02) bootldr = 0x7400; // 3K bootloader
  uint16_t crc = 0xFFFF; 
  // calculate bootloader crc using CRC16-CCITT (with input and output reflection)
  while (bootldr < 0x8000)
  { 
    uint8_t data = pgm_read_byte(bootldr++);
    data ^= crc & 0xFF; 
    data ^= (data << 4) & 0xFF;
    crc  = ((data << 8) | (crc >> 8)) ^ (data >> 4) ^ (data << 3);
  }
  printHexWord(crc);
  //print bootloader version if defined
  uint8_t major = pgm_read_byte(0x7FFA);
  uint8_t minor = pgm_read_byte(0x7FFB);
  if ((major & minor) != 0xFF)
  {
    arduboy.print(F(" v"));
    arduboy.print(char(major));
    arduboy.print('.');
    arduboy.print(char(minor));
  }
  
  if (arduboy.justPressed(A_BUTTON))          EEPROM.update(EEPROM_BOOT_FLAGS,bootflags ^ 0x80);
  else if (arduboy.justPressed(LEFT_BUTTON))  menuState = msFlashchip;
  else if (arduboy.justPressed(RIGHT_BUTTON)) menuState = msModchip;
  else if (arduboy.justPressed(B_BUTTON))     menuState = msMenu;
}

/******************************************************************************/

void modchipInfo()
{
  arduboy.setCursor(16,0);
  arduboy.print(F("MOD CHIP DETAILS"));
  arduboy.drawBitmap(0,43, leftRightBitmap, leftRightBitmapWidth, leftRightBitmapHeight, WHITE);
  arduboy.drawBitmap(99,48, backButtonBitmap, backButtonBitmapWidth, backButtonBitmapHeight, WHITE);

  if (ISP_enable())
  {
    arduboy.setCursor(16,11);
    arduboy.print("Dev:");
    printHexByte(ISP_command(ISP_CMD_READ_ID,0));
    printHexByte(ISP_command(ISP_CMD_READ_ID,1));
    printHexByte(ISP_command(ISP_CMD_READ_ID,2));
    arduboy.print(F(" EEP:"));
    printHexByte(ISP_readEEPROM_00());
    
    arduboy.setCursor(16,19);
    arduboy.print(F("Lfuse:"));
    printHexByte(ISP_readLowFuse());
    arduboy.print(F(" Hfuse:"));
    printHexByte(ISP_readHighFuse());
     
    arduboy.setCursor(16,27); 
    arduboy.print(F("Efuse:"));
    printHexByte(ISP_readExtFuse());
    arduboy.print(F(" Lock: "));
    printHexByte(ISP_readLockBits());
      
    //crc takes a while to calculate do this once on 2nd frame to reduce freeze frame effect
    if (modchipCrcState == 0) ++modchipCrcState;
    else if (modchipCrcState == 1)
    {
      modchipCrc =ISP_getFlashCrc(0,4096 / 2);
      ++modchipCrcState;
    }
    if (modchipCrcState == 2)
    {
      arduboy.setCursor(16,35);
      arduboy.print(F("Firmware CRC:"));
      printHexWord(modchipCrc);
    }
    ISP_disable();
  }
  else 
  {
    arduboy.setCursor(10,28);
    arduboy.print(F("Modchip not found!"));
    modchipCrcState = 0;
  }
      
  if (arduboy.justPressed(LEFT_BUTTON))       menuState = msArduboy;
  else if (arduboy.justPressed(RIGHT_BUTTON)) menuState = msFlashchip;
  else if (arduboy.justPressed(B_BUTTON))     menuState = msMenu;
}

/******************************************************************************/

void setup() 
{
  arduboy.begin();
  arduboy.clear();
  FX_CS_PORT |= _BV(FX_CS_BIT); // disable flash chip
  FX_CS_DDR  |= _BV(FX_CS_BIT);
  CS_PORT |= _BV(CS_BIT);       // disable OLED
}

void loop() 
{
  if(!arduboy.nextFrame()) return;
  
  arduboy.pollButtons();
  arduboy.clear();
  switch(menuState)
  {
    case msMain:            mainScreen(); break;
    case msMenu:            menuScreen(); break;
    case msArduboy:         arduboyInfo(); break;
    case msModchip:         modchipInfo(); break;  
    case msFlashchip:       flashchipInfo(); break;  
    case msHardware:        hardwareInfo(); break;
    case msFlashModchip:    flashModchip(); break;
    case msFlashBootloader: flashBootloader(); break;
  }
  CS_PORT &= ~_BV(CS_BIT); //enable OLED
  arduboy.display();
  CS_PORT |= _BV(CS_BIT); //disable OLED
}
