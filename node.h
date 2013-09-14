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
	uint8_t updateShortInputs(uint16_t index, uint16_t length);
	uint8_t updateHoldings(uint16_t index, uint16_t length);

	Ds18b20 *_tmp;
	DigitalPin * _sw;

	PwmPin * _fan;
	DigitalPin * _beeper;

	static const uint8_t _uuid[];
	static const uint8_t _lengths[];
};

#endif /* NODE_H_ */
