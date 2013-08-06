/*
 * node.h
 *
 *  Created on: Aug 3, 2013
 *      Author: agu
 */

#ifndef NODE_H_
#define NODE_H_

#include "modbus/slave-rtu.h"
#include "digitalpin/digitalpin.h"
#include "adcpin/adcpin.h"
#include "drv_hd44780/drv_hd44780.h"

class Node: public SlaveRtu {
public:
	Node(HardwareSerial & usart, uint8_t address, uint8_t de, uint8_t re);
	virtual ~Node();
	void init();

private:
	DigitalPin ** _coil_pins;
	uint8_t updateCoils(uint16_t index, uint16_t length);

	DigitalPin ** _bit_input_pins;
	uint8_t updateBitInputs(uint16_t index, uint16_t length);

	AdcPin ** _short_input_pins;
	uint8_t updateShortInputs(uint16_t index, uint16_t length);

	uint8_t updateHoldings(uint16_t index, uint16_t length);

	void process(uint8_t command);

	DrvHd44780 _lcd;
};

#endif /* NODE_H_ */
