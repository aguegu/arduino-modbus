#!/usr/bin/env python
import minimalmodbus
import time

x = minimalmodbus.Instrument('/dev/ttyACM0', 3) 
x.serial.parity = 'E'
#x.serial.timeout = 0.1
print "uuid: %s" % x.read_string(0, 16, 4)

print

print "bit_input: %d" % x.read_register(16, 0, 4, False)
print "coil: %d" % x.read_register(17, 0, 4, False)
print "short_input: %d" % x.read_register(18, 0, 4, False)
print "holding: %d" % x.read_register(19, 0, 4, False)

print

print "short inputs:"
print "[0].type: %d" % x.read_register(20, 0, 4, False)
tmp = x.read_register(21, 0, 4, False)
print "[0].value: %d" % tmp
print "[0].value: %f" % (tmp / 16.0)
print

print "[1].type: %d" % x.read_register(22, 0, 4, False)
print "[1].value: %d" % x.read_register(23, 0, 4, False)

print

print "holdings: "
print "[0].type: %d" % x.read_register(0, 0, 3, False)
x.write_register(1, 100, 0, 6, False)
print "[0].value: %d" % x.read_register(1, 0, 3, False)
print

print "[1].type: %d" % x.read_register(2, 0, 3, False)
x.write_register(3, 1, 0, 6, False)
print "[1].value: %d" % x.read_register(3, 0, 3, False)
print

time.sleep(0.2)

x.write_register(1, 10, 0, 6, False)
print "[0].value: %d" % x.read_register(1, 0, 3, False)

x.write_register(3, 0, 0, 6, False)
print "[1].value: %d" % x.read_register(3, 0, 3, False)


'''
print x.read_bit(0, 2);

x.write_bit(0, 1, 5)
print x.read_bit(0, 1)
time.sleep(0.2)

x.write_bit(0, 0, 15)
print x.read_bit(0, 1)

adc = x.read_register(0, 0, 4, False)
print "%4d\t%.2f%%" % (adc, adc / 16.0)

fan = x.write_register(0, 100, 0, 6, False)

x.write_string(10, "hello", 3)
print x.read_string(10, 3, 3)

x.write_string(10, "world", 3)
print x.read_string(10, 3, 3)

03050000ff008dd8
030500000000cc28

00050000ff008DEB
000500000000CC1B

'''
