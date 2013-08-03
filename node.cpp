/*
 * node.cpp
 *
 *  Created on: Aug 3, 2013
 *      Author: agu
 */

#include "node.h"

Node::Node(HardwareSerial & usart, uint8_t address, uint8_t de, uint8_t re) :
		SlaveRtu(usart, address, de, re) {
	this->initBitInputs(0);
	this->initCoils(1);
	this->initShortInputs(0);
	this->initHoldings(0);

	_coil_pins = (DigitalPin **) malloc(_coil_length * sizeof(DigitalPin *));

	_coil_pins[0] = new DigitalPin(13, OUTPUT);
}

Node::~Node() {

	for (uint8_t i = 0; i < _coil_length; i++)
			delete _coil_pins[i];
	free(_coil_pins);
}

void Node::init() {
	this->SlaveRtu::init();
}

uint8_t Node::updateCoils(uint16_t index, uint16_t length) {
	for (uint16_t i = 0; i < length; i++)
		_coil_pins[index + i]->set(this->getCoil(index + i));
	return 0;
}
