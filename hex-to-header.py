print('\nHex file to C header coverter v1.02 by Mr.Blinky Jan-Aug 2020\n')

import sys
import time
import os

def DelayedExit():
    time.sleep(2)
    sys.exit()

def convert(filename):
    f = open(filename,'r')
    records = f.readlines()
    f.close()
    f = open(filename.replace('.hex','.h'),'w')
    data_addr  = -1
    data_tmp   = -1
    flash_data = ''
    name = os.path.basename(filename).replace('.hex','').replace(' ','_').replace('-','_').replace('.','_')
    f.write('#pragma once\n\nconst unsigned char {}[] PROGMEM = {{\n'.format(name))
    for rcd in records :
        if rcd == ':00000001FF' : break
        if rcd[0] == ':' :
            rcd_len  = int(rcd[1:3],16)
            rcd_typ  = int(rcd[7:9],16)
            rcd_addr = int(rcd[3:7],16)
            rcd_sum  = int(rcd[9+rcd_len*2:11+rcd_len*2],16)
            if (rcd_typ == 0) and (rcd_len > 0) :
                if rcd_addr != data_addr:
                    data_start = data_tmp
                    data_len   = data_addr - data_tmp
                    if data_len:
                        f.write('  //Flash block: 0x{:04x} bytes at 0x{:04x}\n'.format(data_len, data_start))
                        f.write('  0x{:02x}, 0x{:02x}, //LSB, MSB Program word length\n'.format((data_len >> 1) & 0xFF, data_len >> 9))
                        f.write('  0x{:02x}, 0x{:02x}, //LSB, MSB Program word address\n'.format((data_start >> 1) & 0xFF, data_start >> 9))
                        f.write(flash_data)
                        f.write('\n')
                        flash_data = ''
                    data_tmp  = rcd_addr
                data_addr = rcd_addr
                checksum = rcd_sum
                flash_data = flash_data + ' '
                for i in range(1,9+rcd_len*2, 2) :
                    byte = int(rcd[i:i+2],16)
                    checksum = (checksum + byte) & 0xFF
                    if i >= 9:
                        flash_data = flash_data +' 0x{},'.format(rcd[i:i+2])
                        data_addr += 1
                if checksum != 0 :
                    print('Error: Hex file "{}" contains errors.'.format(filename))
                    DelayedExit()
                flash_data = flash_data + '\n' 
    data_start = data_tmp
    data_len = data_addr - data_tmp
    f.write('  //Flash block: 0x{:04x} bytes at 0x{:04x}\n'.format(data_len, data_start))
    f.write('  0x{:02x}, 0x{:02x}, //LSB, MSB Program word length\n'.format((data_len >> 1) & 0xFF, data_len >> 9))
    f.write('  0x{:02x}, 0x{:02x}, //LSB, MSB Program word address\n'.format((data_start >> 1) & 0xFF, data_start >> 9))
    f.write(flash_data)
    f.write('\n  //Zero length end marker\n  0x00, 0x00\n};\n')
    f.close()
    return
        
################################################################################

if len(sys.argv) < 2 :
    print('\nUsage: {} filename.hex\n'.format(os.path.basename(sys.argv[0])))
    print('Convert an Intel hex file into a C header file.')
    DelayedExit()

for filenumber in range (1,len(sys.argv)): #support multiple files
    hexfile = os.path.abspath(sys.argv[filenumber])
    path = os.path.dirname(hexfile)+os.sep
    if not os.path.isfile(hexfile) :
        print('Error: hex file "{}" not found.'.format(hexfile))
        DelayedExit()
    filename = path + os.path.basename(hexfile).replace('.hex','.h')
    convert(hexfile)
    print('Converted hex file "{}"'.format(hexfile))
DelayedExit()
