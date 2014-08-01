/*
 * Arduino.cpp
 *
 *  Created on: 31/07/2014
 *      Author: root
 */

#include <Arduino.h>

/// BBB
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
#include <sys/time.h>


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

double start_time = 0;

//
unsigned long micros(void){
	struct timeval start;
	gettimeofday(&start, NULL);
	double seconds = start.tv_sec + start.tv_usec/1000000.0;
        if(start_time==0){
           start_time=seconds;
	   gettimeofday(&start, NULL);
	   seconds = start.tv_sec + start.tv_usec/1000000.0;
        }

	double micros = (seconds-start_time)*1000000.0;


	unsigned long ret = micros;
	printf("micros %lu\r\n",ret);
	return micros;
}

unsigned long millis(void){
	struct timeval start;
	gettimeofday(&start, NULL);
	double seconds = start.tv_sec + start.tv_usec/1000000.0;
        if(start_time==0){
           start_time=seconds;
	   gettimeofday(&start, NULL);
	   seconds = start.tv_sec + start.tv_usec/1000000.0;
        }

	double millis = (seconds-start_time)*1000.0;
	unsigned long ret = millis;
	printf("millis %lu\r\n",ret);
	return millis;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//
void delay(unsigned long ms){
	printf("delay=%lu\r\n",ms);
	usleep(ms*1000);
}
void delayMicroseconds(unsigned int us){
	printf("delayMicroseconds=%d\r\n",us);
	usleep(us);
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//
void digitalWrite(uint8_t pin, uint8_t value){
	printf("digitalWrite pin=%d value=%d\r\n",pin,value);
}

void pinMode(uint8_t pin, uint8_t mode){
	printf("pinmode pin=%d mode=%d\r\n",pin,mode);
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

