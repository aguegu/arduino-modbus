// Do not remove the include below
#include "arduino-modbus.h"

#include "digitalpin/digitalpin.h"
#include "node.h"

Node node(Serial, 0x03, 2, 2);

void setup() {
	node.init();
}

void loop() {
	node.handler();
}

