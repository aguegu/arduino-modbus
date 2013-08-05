#!/usr/bin/env python
import minimalmodbus
import time

node_stm32 = minimalmodbus.Instrument('/dev/ttyUSB0', 2) 
node_stm32.serial.parity = 'E'

node_arduino = minimalmodbus.Instrument('/dev/ttyUSB0', 3) 
node_arduino.serial.parity = 'E'

print "\nNode stm32:"
print "-" * 32
print node_stm32.read_bit(0, 2)
print node_stm32.read_bit(1, 2)

node_stm32.write_bit(0, 1, 5)
print node_stm32.read_bit(0, 1)

node_stm32.write_bit(0, 0, 15)
print node_stm32.read_bit(0, 1)

adc = node_stm32.read_register(0, 0, 4, False)
print "%4d\t%.2f%%" % (adc, adc / 40.95)
adc = node_stm32.read_register(1, 0, 4, False)
print "%4d\t%.2f%%" % (adc, adc / 40.95)

node_stm32.write_string(10, "hello", 3)
print node_stm32.read_string(10, 3, 3)

node_stm32.write_string(10, "world", 3)
print node_stm32.read_string(10, 3, 3)

print "\nNode arduino:"
print "-" * 32

print node_arduino.read_bit(0, 2);

node_arduino.write_bit(0, 1, 5)
print node_arduino.read_bit(0, 1)
time.sleep(0.2)

node_arduino.write_bit(0, 0, 15)
print node_arduino.read_bit(0, 1)

adc = node_arduino.read_register(0, 0, 4, False)
print "%4d\t%.2f%%" % (adc, adc / 10.23)

node_arduino.write_string(10, "hello", 3)
print node_arduino.read_string(10, 3, 3)

node_arduino.write_string(10, "world", 3)
print node_arduino.read_string(10, 3, 3)
