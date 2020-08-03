/*******************************************************************************
Arduboy ModChip loader v1.02 (ATtiny version) Dec 2019 -Apr 2020 by Mr.Blinky

Firmware for Attiny 45/85 to update Arduboy bootloader

Licenced under MIT

ARDUBOY    |    Attiny wiring       | ARDUBOY            
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
#include <avr/sleep.h>
#include "isp.h"
#include "arduboy3k-bootloader-sda.h"

// Arduboy bootloader code and fusesettings
#define BOOTLOADER_DATA arduboy3k_bootloader_sda
#define LOW_FUSE     0xFF
#define HIGH_FUSE    0xD2 // bootloader size 1K word, Preserve EEPROM on chip erase
#define EXT_FUSE     0xCB 
#define LOCK_BITS    0xFF 

#define FX_CS_BIT   PB3 // port pin connected to FX flash chip select
#define AB_RST_BIT  PB4 // port pin connected to Arduboy reset

/** Pin change interrupt only used to wake-up from powerdown **/

EMPTY_INTERRUPT(PCINT0_vect);

/** save a few 100s of micro Amps **/

void reducePower() // reduce all power including timer 0
{
 PRR = _BV(PRTIM1) | // disable timer 1 power (not used and consumes most power),
       _BV(PRTIM0) | // disable timer 0 power (normally used for millis timer)
       _BV(PRUSI)  | // disable USI power (not used as SPI is bitbanged)
       _BV(PRADC);   // disable ADC power (also not used)
}

/** powering down will save a lot of power (current < 1 micro Amps) **/

void powerDown()
{
  PCMSK = _BV(AB_RST_BIT);                  // allow Arduboy reset to wake up from powerdown mode
  GIMSK = _BV(PCIE);                        // enable pin change interrupt 
  MCUCR = SLEEP_MODE_PWR_DOWN | _BV(SE);    // enable power down mode
  sei();                                    // enable interrupts
  sleep_cpu();                              //power down now
  // Pin change interrupt has woken up the attiny at this point
  MCUCR = 0;                                //disable sleep mode
  GIMSK = 0;                                //disable pin change interrupt
}

/** Interrups are not used (except for wake up) so we can do some simple cycle counting for delays **/

void delayMillis(uint8_t millis)
{
  uint8_t temp;
  asm volatile
  (
    "1: ldi     %[temp], 250    \n" //250 * 4 cycles @ 1Mhz = 1msec
    "2: nop                     \n"
    "   dec     %[temp]         \n"
    "   brne    2b              \n"
    "   dec     %[millis]       \n"
    "   brne    1b              \n"
    : [millis] "+r" (millis),
      [temp]    "+d" (temp)
  );
}

/** EEPROM functions **/

uint8_t /*__attribute__ ((noinline))*/ EEPROM_readByte(uint16_t addr)
{
  while (EECR & _BV(EEPE)); //wait in case of pending EEPROM write
  EEAR = addr;
  EECR |= _BV(EERE); //EEPROM read enable strobe
  return EEDR;
}

void EEPROM_updateByte(uint16_t addr, uint8_t data)
{
  uint8_t oldData = EEPROM_readByte(addr);
  if (oldData == data) return; // no changes
  
  uint8_t mode = (0 << EEPM1) | (0 << EEPM0); //default to erase before write
  if ((oldData & data) == data) // only new 0 bits, no erase required
  {
    mode = (1 << EEPM1) | (0 << EEPM0); // write without erase
    data = ~(oldData ^ data); //set old 0 bits to 1 for wear leveling.
  }
  EECR = mode;
  EEDR = data;
  EECR |= _BV(EEMPE); // set EEPROM master program enable
  EECR |= _BV(EEPE); // set EEPROM program enable
}

/** the flasher **/

void flashBootloader()
{
  if (!ISP_enable()) return; // failed to enter ISP mode
  
  bool erased = false;
  if ((ISP_readLockBits() | ISP_LOCKBITS_MASK) != LOCK_BITS)
  {
    ISP_eraseChip(); //only way to clear lock bits
    erased = true;
  }
  if (ISP_readLowFuse != LOW_FUSE) ISP_writeLowFuse(LOW_FUSE);
  if (ISP_readHighFuse != HIGH_FUSE) ISP_writeHighFuse(HIGH_FUSE);
  if (ISP_readExtFuse != EXT_FUSE) ISP_writeExtFuse(EXT_FUSE);
  if (!erased) ISP_eraseChip();  
  ISP_writeProgramFlash(BOOTLOADER_DATA);
  if (ISP_verifyProgramFlash(BOOTLOADER_DATA)) EEPROM_updateByte(0, 0xB1);
  ISP_disable();
}

/** All hardware is initialized here **/

void setup() 
{
  DDRB  = 0;                // all pins as input
  PORTB = _BV(FX_CS_BIT);   // pullup on flash chips select
  MCUCR = 0;                // Make sure pullups are enabled (PUD is off)
  
  PRR = _BV(PRTIM1) |   // disable timer 1 power (not used and consumes most power),
        _BV(PRTIM0) |   // disable timer 0 power (normally used for millis timer)
        _BV(PRUSI)  |   // disable USI power (not used as SPI is bitbanged)
        _BV(PRADC);     // disable ADC power (also not used)
  if (EEPROM_readByte(0) == 0xFB) 
  {
    delayMillis(20);
    flashBootloader();
  }
}

/** main loop **/

void loop()
{
 powerDown(); // powering down here so setup ends with powerdown
 
// woke up from powerdown because Ardunboy's reset button was pressed.
// test how long the reset button is being pressed
 
 uint16_t resetLow  = 0; 
 uint8_t resetHigh = 0;
 while (resetHigh < 20) // reset must be inactive high for 20 msec after active low reset (button debounce)
 {
   while (!(PINB & _BV(AB_RST_BIT))) // Arduboy reset button pressed
   { 
     resetHigh = 0;
     delayMillis(1);
     if (resetLow < 65535) ++resetLow;
   }
   delayMillis(1);
   ++resetHigh;
 }
 if (resetLow >= 2000) flashBootloader(); //Only flash bootloader when reset was pressed for at least 2 seconds.
}
