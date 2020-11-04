# Arduboy FX mod-chip

The Arduboy FX mod-chip is a small flex PCB that is installed into an original Arduboy.
It consists of a 16 Mbyte serial flash memory chip (W25Q128) and a small MCU (Attiny45/85).
The flash chip function is to store all Arduboy games and the MCU function is to effortlessly
update Arduboy's bootloader without the need to open up Arduboy and using an ISP programmer.
With the new bootloader installed any of the games stored in the flash chip can be selected to
play on the go without the need connect to a PC.

## Arduboy FX Activator

The Arduboy FX mod-chip must be programmed with firmware and a flash image containing the game
collection. The Arduboy FX Activator tool is required to do that. It consists of an Arduboy
program and a Python GUI script.

The python GUI script is graphical tool to easily upload the the Arduboy program to Arduboy
and also upload the flash image to the serial flash memory. The flash image contains the
games collection. 

The Arduboy program is used to install/update the firmware into the mod-chip MCU and update
the Arudboy bootloader.

## Portable Activator

### How to - PC part

The folder **portable-activator** contains the GUI python script file and Arduboy .hex file.
It also contains an all in-one zip file targeted for Windows users that contains a stand alone
version of Python 3 to run the script.

Windows users can unpack the zip file and double click the **run-fx-activator-windows.bat** to run
the tool.Linux and OSX users can run the **fx-activator.py** using Python launcher.
For Linux and OSX users: Make sure PySerial module is installed otherwise the tool wont work.

![screenshot](https://github.com/MrBlinky/Arduboy-FX-mod-chip/raw/master/portable-activator/screenshot-running.png)


### How to - Arduboy part

The status of the mod-chip is displayed on the title screen. If correctly installed you will see a V checkmark after both the flash chip and mod chip. If you see a X after either chip, the mod chip is not functioning properly and you should inspect the mod chip for shorts or bad solderjoints. Before starting any flashing process, make sure Arduboy is fully charged or connected to USB.

![titlescreen](https://github.com/MrBlinky/Arduboy-FX-mod-chip/raw/master/portable-activator/fx-activator-titlescreen.png)

Pressing the A-button on the title screen will show the menu. There are 4 options to choose from:
- Dignostic Info
- Power on with menu
- Flash mod chip
- Flash bootloader

The DIAGNOSTIC INFO shows information about Arduboy bootloader, The mod chip MCU and flash chip as a trouble shooting aid.

The Poweron with menu or Power on with game option will determines which firmware version is flashed to the MCU.

The FLASH MOD CHIP option will flash the mod chip MCU with firmware which also contains the Arduboy bootloader. If the verification fails, you should inspect the mod chip for shorts or bad solderjoints.
* If the POWER ON WITH MENU option is displayed in the menu. The firmware will include the bootloader that starts with the menu when Switching power on.
* If the POWER ON WITH GAME option is displayed in the menu. The firmware will include the bootloader that starts the last burned game when Switching power on.

The flash bootloader option will instruct the mod chip MCU to flash Arduboy bootloader and fuse settings. This process will take a few seconds to complete.
The screen may turn black during this process. After completion Arduboy will reset into the bootloader and a USB icon or the menu loader screen is displayed.

After the bootloader is updated the flash image can be uploaded using the GUI tool.

![menu](https://github.com/MrBlinky/Arduboy-FX-mod-chip/raw/master/portable-activator/fx-activator-menu.png)
