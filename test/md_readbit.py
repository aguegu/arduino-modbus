#!/usr/bin/env python
import minimalmodbus
import time

x = minimalmodbus.Instrument('/dev/ttyACM0', 3) 
x.serial.parity = 'E'
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

