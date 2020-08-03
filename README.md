# Arduboy FX mod-chip

The Arduboy FX mod-chip is a small flex PCB that is installed into an original Arduboy.
It consists of a 16 Mbyte serial flash memory chip (W25Q128) and a small MCU (Attiny45/85).
The flash chip function is to store all Arduboy games and the MCU function is to effortlessly
update Arduboy's bootloader without the need to open up Arduboy and using an ISP programmer.
With the new bootloader installed any of the games stored in the flash chip can be selected to
play on the go without the need connect to a PC.

## Arduboy FX Activator

The Arduboy FX Activator consists of an Arduboy program(sketch) and a Python GUI script to 
upload this program. The Arduboy program will install/update the firmware into the Arduboy FX
mod-chip MCU. With the firmware installed, this program is is also used to update Arduboy's 
bootloader.

The python GUI script is graphical tool to easily upload the the Arduboy program to Arduboy
and also upload a flash image containing all the games to the flash chip. 

## Portable Activator

The folder **portable-activator** contains the GUI python script file and Arduboy .hex file.
It also contains an all in-one zip file targeted for Windows users that containing Python 3.

Windows users can unpack the zip file and run the **run-fx-activator-windows.bat** to run the tool.
Linux and OSX users can run the **fx-activator.py** using Python launcher.
For Linux and OSX users: Make sure PySerial module is installed otherwise the tool wont work.

![screenshot](https://github.com/MrBlinky/Arduboy-FX-mod-chip/raw/master/portable-activator/screenshot-running.png)
