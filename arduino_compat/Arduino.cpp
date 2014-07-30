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

void _Serial::begin(int d){ printf("serial begin %d\r\n",d); }
void _Serial::print(char c){ printf("%c",c); }
void _Serial::print(char* str){ printf("%s",str); }
void _Serial::print(int d,int f){ printf("d=%d f=%d",d,f); }
void _Serial::println(){ printf("\r\n"); }
void _Serial::println(char c){ print(c); println(); }
void _Serial::println(char* str){ print(str); println(); }
void _Serial::println(int d,int f){ print(d,f); println(); }
void _Serial::write(int v){ printf("serial.write=%d\r\n",v); }
int _Serial::available(){ return 1;}
int _Serial::read(){ return getchar(); }
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

int _EEPROM::read(int addr){ int value=1; printf("eeprom read addr=%d value=%d\r\n",addr,value); return 0; }
void _EEPROM::write(int addr,int value){ printf("eeprom write addr=%d value=%d\r\n",addr,value); }

_EEPROM EEPROM;
