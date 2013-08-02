#include "modbus.h"
#include "digitalpin.h"
#include "slave-rtu.h"

SlaveRtu node(Serial, 0x02, 2, 3);

void setup() {
	node.init();
}

void loop() {
	node.handler();
}
