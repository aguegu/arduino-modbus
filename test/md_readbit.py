#!/usr/bin/env python
import minimalmodbus
import time

x = minimalmodbus.Instrument('/dev/ttyUSB0', 3) 
x.serial.parity = 'E'

print x.read_bit(0, 2);

x.write_bit(0, 1, 5)
print x.read_bit(0, 1)
time.sleep(0.2)

x.write_bit(0, 0, 15)
print x.read_bit(0, 1)

adc = x.read_register(0, 0, 4, False)
print "%4d\t%.2f%%" % (adc, adc / 10.23)

s = "hello, world."
reg_len = (len(s) + 1) / 2
x.write_string(0, s, reg_len)
x.write_string(8, s, reg_len)
x.write_string(16, s, reg_len)
x.write_string(24, s, reg_len)

print x.read_string(0, reg_len, 3)



'''
03050000ff008dd8
030500000000cc28

00050000ff008DEB
000500000000CC1B

'''
