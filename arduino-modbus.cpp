// Do not remove the include below
#include "arduino-modbus.h"

#include "node.h"
#include "digitalpin/digitalpin.h"
#include "drv_hd44780/drv_hd44780.h"

Node node(Serial, 0x03, 2, 3);

void setup() {
	node.init();
}

void loop() {
	node.handler();
}

