/*
 * Arduino.cpp
 *
 *  Created on: 30/07/2014
 *      Author: root
 */

#include "Arduino.h"


//
int micros(){ return 0; }
int millis(){ return 0; }

//
void delay(int ms){}
void delayMicroseconds(int us){}

//
void digitalWrite(int,int){}
void pinMode(int, int){}

void _Serial::begin(int){}
void _Serial::print(char){}
void _Serial::print(char*){}
void _Serial::print(int,int){}
void _Serial::println(){}
void _Serial::println(char){}
void _Serial::println(char*){}
void _Serial::println(int,int){}
void _Serial::write(int){}
int _Serial::available(){ return 0;}
int _Serial::read(){ return 0;}

_Serial Serial;

void _SPI::begin(){}
int _SPI::transfer(int){return 0;}

_SPI SPI;

void _Wire::begin(){}
void _Wire::beginTransmission(int _dev_address){}
int _Wire::endTransmission(){return 0;}
void _Wire::write(uint8_t value){}
void _Wire::requestFrom(int _dev_address,int _nbytes){}
int _Wire::available(){return 0;}
uint8_t _Wire::read(){return 0;}
void _Wire::send(int){}
int _Wire::receive(){return 0;}

_Wire Wire;

int _EEPROM::read(int){return 0; }
void _EEPROM::write(int,int){ }

_EEPROM EEPROM;
