/*
 * Arduino.h
 *
 *  Created on: 30/07/2014
 *      Author: root
 */

#ifndef ARDUINO_H_
#define ARDUINO_H_

/*
#include <assert.h>	//Conditionally compiled macro that compares its argument to zero
#include <complex.h> //(since C99)	Complex number arithmetic
#include <ctype.h>	//Functions to determine the type contained in character data
#include <errno.h>	//Macros reporting error conditions
#include <fenv.h> //(since C99)	Floating-point environment
#include <float.h>	//Limits of float types
#include <inttypes.h> //(since C99)	Format conversion of integer types
#include <iso646.h> //(since C99)	Alternative operator spellings
#include <limits.h>	//Sizes of basic types
#include <locale.h>	//Localization utilities
#include <math.h>	//Common mathematics functions
#include <setjmp.h>	//Nonlocal jumps
#include <signal.h>	//Signal handling
#include <stdalign.h> //(since C11)	Type alignment control
#include <stdarg.h>	//Variable arguments
//#include <stdatomic.h> //(since C11)	Atomic types
#include <stdbool.h> //(since C99)	Macros supporting type bool
#include <stddef.h>	//Common macro definitions
#include <stdint.h> //(since C99)	Fixed-width integer types
#include <stdio.h>	//Input/output
#include <stdlib.h>	//General utilities: memory management, program utilities, string conversions, random numbers
#include <stdnoreturn.h> //(since C11)	Non-returning functions
#include <string.h>	//String handling
#include <tgmath.h> //(since C99)	Type-generic math (macros wrapping math.h and complex.h)
//#include <threads.h> //(since C11)	Thread library
#include <time.h>	//Time/date utilities
#include <uchar.h> //(since C11)	UTF-16 and UTF-32 character utilities
#include <wchar.h> //(since C99)	Extended multibyte and wide character utilities
#include <wctype.h> //(since C99)	Wide character classification and mapping utilities
*/

#include "cppheaders.h"

enum ___levels {LOW, HIGH};
enum ___numericbase { HEX,DEC,BIN };
enum ___direction { INPUT, OUTPUT };

typedef uint8_t byte;

//
int micros();
int millis();

//
void delay(int ms);
void delayMicroseconds(int us);

//
void digitalWrite(int,int);
void pinMode(int, int);

#define min(a,b)  a<b?a:b
#define max(a,b)  a>b?a:b

#define B00000000 0
#define B00000001 1
#define B00000010 2
#define B00000011 3
#define B110      6
#define B00001111 15
#define B11101100 236
#define B11110000 240

class _Serial {
public:
	void print(char);
	void print(char*);
	void print(int,int);

	void println(char);
	void println(char*);
	void println(int,int);

	void write(int);
};

class _SPI {
public:
    void begin();
    int transfer(int);
};
extern _SPI SPI;
extern _Serial Serial;

class _Wire {
public:
	void beginTransmission(int _dev_address);
	int endTransmission();
	void write(uint8_t value);
	void requestFrom(int _dev_address,int _nbytes);
	int available();

	uint8_t read();
	void send(int);
	int receive();
};

extern _Wire Wire;

class _EEPROM {
public:
    int read(int);
};

extern _EEPROM EEPROM;



#endif /* ARDUINO_H_ */
