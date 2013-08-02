// Do not remove the include below
#include "arduino-modbus.h"

#include "digitalpin.h"
#include "slave-rtu.h"

SlaveRtu node(Serial, 0x03, 2, 3);

void setup() {
	node.init();
}

void loop() {
	node.handler();
}

