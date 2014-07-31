/*
 * Arduino.h
 *
 *  Created on: 30/07/2014
 *      Author: root
 */

#ifndef ARDUINO_H_
#define ARDUINO_H_

#include <stdio.h>
#include <stdint.h>
#include <math.h>

enum ___levels {LOW, HIGH};
enum ___numericbase { HEX,DEC,BIN };
enum ___direction { INPUT, OUTPUT };

typedef uint8_t byte;

#define F_CPU 16000000L

#define B00000000 0
#define B00000001 1
#define B00000010 2
#define B00000011 3
#define B110      6
#define B00001111 15
#define B11101100 236
#define B11110000 240

#define min(a,b)  a<b?a:b
#define max(a,b)  a>b?a:b

//
long micros();
long millis();

//
void delay(int ms);
void delayMicroseconds(int us);

//
void digitalWrite(int,int);
void pinMode(int, int);

class _Serial {
public:
        int fd;
	void begin(int);
        void socat_link(char*);
	void print(char);
	void print(char*);
	void print(int,int);

	void println();
	void println(char);
	void println(char*);
	void println(int,int);

	int available();
	int read();
	void write(uint8_t);
};
extern _Serial Serial;

class _SPI {
public:
    void begin();
    int transfer(int);
};
extern _SPI SPI;

class _Wire {
public:
    void begin();
	void beginTransmission(int _dev_address);
	int endTransmission();
	void write(uint8_t value);
	void requestFrom(int _dev_address,int _nbytes);
	int available();

	uint8_t read();
	void send(int);
	int receive();

	int fd;
	int addr;
	uint8_t buffer[1024];
	int rx_count;
        int rx_idx;
};

extern _Wire Wire;

class _EEPROM {
public:
    uint8_t mem[2048];
    _EEPROM();
    int read(int);
    void write(int,int);
};

extern _EEPROM EEPROM;



#endif /* ARDUINO_H_ */
