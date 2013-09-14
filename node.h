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
#include "pwmpin/pwmpin.h"
#include "ds18b20/ds18b20.h"

class Node: public SlaveRtu {
public:
	Node(HardwareSerial & usart, uint8_t address, uint8_t de, uint8_t re);
	virtual ~Node();
	void init();

private:
//	DigitalPin ** _coil_pins;
//	uint8_t updateCoils(uint16_t index, uint16_t length);
//
//	DigitalPin ** _bit_input_pins;
//	uint8_t updateBitInputs(uint16_t index, uint16_t length);

	AdcPin ** _short_input_pins;
	uint8_t updateShortInputs(uint16_t index, uint16_t length);

	PwmPin * _fan;
	uint8_t updateHoldings(uint16_t index, uint16_t length);

	Ds18b20 *_tmp;

	static const uint8_t _uuid[];
	static const uint8_t _lengths[];
};

#endif /* NODE_H_ */
