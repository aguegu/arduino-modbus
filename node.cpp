/*
 * node.cpp
 *
 *  Created on: Aug 3, 2013
 *      Author: agu
 */

#include "node.h"

const uint8_t Node::_uuid[] = "b66dce621d5d11e38e9ba77460cc2a25";
const uint8_t Node::_lengths[] = { 0, 0, 2, 2 };

Node::Node(HardwareSerial & usart, uint8_t address, uint8_t de, uint8_t re) :
		SlaveRtu(usart, address, de, re) {
	this->initBitInputs(_lengths[0]);
	this->initCoils(_lengths[1]);
	this->initShortInputs(20 + _lengths[2] * 2);
	this->initHoldings(_lengths[3] * 2);

	// short_inputs
	_tmp = new Ds18b20(10);
	_sw = new DigitalPin(12, INPUT_PULLUP);

	// holdings
	_fan = new PwmPin(9);
	_beeper = new DigitalPin(11, OUTPUT);

	for (uint8_t i = 0; i < 16; i++)
		this->setShortInput(i, make16(_uuid[i + i], _uuid[i + i + 1]));

	for (uint8_t i = 0; i < 4; i++)
		this->setShortInput(i + 16, _lengths[i]);

	this->setShortInput(20 + 0, 4);
	this->setShortInput(20 + 2, 2);

	this->setHolding(0, 3);
	this->setHolding(2, 6);

	_beeper->set(true);
}

Node::~Node() {
	free(_tmp);
	free(_sw);

	free(_fan);
	free(_beeper);
}

void Node::init() {
	this->SlaveRtu::init();
	_tmp->init();
}

uint8_t Node::updateShortInputs(uint16_t index, uint16_t length) {
	for (uint16_t i = 0; i < length; i++) {
		uint16_t j = index + i;
		switch (j) {
		case 21:
			this->setShortInput(j, _tmp->getValue());
			_tmp->convert();
			break;
		case 23:
			this->setShortInput(j, _sw->read() ? 0x0000 : 0xffff);
			break;
		}
	}
	return 0;
}

uint8_t Node::updateHoldings(uint16_t index, uint16_t length) {
	for (uint16_t i = 0; i < length; i++) {
		uint16_t k = index + i;
		switch (k) {
		case 1:
			_fan->setPWM(this->getHolding(k));
			break;
		case 3:
			_beeper->set(!this->getHolding(k));
			break;
		}
	}

	return 0;
}

