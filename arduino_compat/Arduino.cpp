/*
 * Arduino.cpp
 *
 *  Created on: 30/07/2014
 *      Author: root
 */

#include "Arduino.h"

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//
int micros(){
	return 0;
}

int millis(){
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//
void delay(int ms){
	usleep(ms*1000);
}
void delayMicroseconds(int us){
	usleep(us);
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//
void digitalWrite(int,int){}
void pinMode(int, int){}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void _SPI::begin(){

}

int _SPI::transfer(int x){
	return x;
}

_SPI SPI;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void _Wire::begin(){

	printf("enable I2C-2 overlay\r\n");
	system("echo BB-I2C1 > /sys/devices/bone_capemgr.9/slots");
	printf("wait I2C-2 overlay to be ready\r\n");
	usleep(1000000);

	if ((this->fd = open("/dev/i2c-2",O_RDWR)) < 0) {
		printf("Failed to open the bus.");
		exit(1);
	}

}
void _Wire::beginTransmission(int _dev_address){
	if (ioctl(this->fd,I2C_SLAVE,_dev_address) < 0) {
		printf("Failed to acquire bus access and/or talk to slave.\n");
	}
}
int _Wire::endTransmission(){
	return 0;
}

void _Wire::write(uint8_t value){
	::write(this->fd,&value,1);
}

void _Wire::send(int value){
	this->write(value);
}

uint8_t _Wire::read(){
	uint8_t value;
	::read(this->fd,&value,1);
	return 0;
}

int _Wire::receive(){
	return this->buffer[this->rx_count--];
}

void _Wire::requestFrom(int _dev_address,int _nbytes){
	if (ioctl(this->fd,I2C_SLAVE,_dev_address) < 0) {
		printf("Failed to acquire bus access and/or talk to slave.\n");
	}
	printf("wire.requestFrom addr=%d n=%d\r\n",_dev_address,_nbytes);
	this->rx_count=::read(this->fd,this->buffer,sizeof(this->buffer));
}

int _Wire::available(){
	return this->rx_count;
}

_Wire Wire;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

int _EEPROM::read(int addr){
	int value=1;
	printf("eeprom read addr=%d value=%d\r\n",addr,value);
	return 0;
}

void _EEPROM::write(int addr,int value){
	printf("eeprom write addr=%d value=%d\r\n",addr,value);
}

_EEPROM EEPROM;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


