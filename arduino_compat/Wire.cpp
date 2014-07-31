/*
  TwoWire.cpp - TWI/I2C library for Wiring & Arduino
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
*/

extern "C" {
  #include <stdlib.h>
  #include <string.h>
  #include <inttypes.h>
  //#include "twi.h"

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

}

#include "Wire.h"

// Initialize Class Variables //////////////////////////////////////////////////

uint8_t TwoWire::rxBuffer[BUFFER_LENGTH];
uint8_t TwoWire::rxBufferIndex = 0;
uint8_t TwoWire::rxBufferLength = 0;

uint8_t TwoWire::txAddress = 0;
uint8_t TwoWire::txBuffer[BUFFER_LENGTH];
uint8_t TwoWire::txBufferIndex = 0;
uint8_t TwoWire::txBufferLength = 0;

uint8_t TwoWire::transmitting = 0;

void (*TwoWire::user_onRequest)(void);
void (*TwoWire::user_onReceive)(int);

// Constructors ////////////////////////////////////////////////////////////////

TwoWire::TwoWire()
{
	printf("enable I2C-2 overlay\r\n");
	system("echo BB-I2C1 > /sys/devices/bone_capemgr.9/slots");
	printf("wait I2C-2 overlay to be ready\r\n");
	usleep(1000000);

	if ((this->fd = open("/dev/i2c-2",O_RDWR)) < 0) {
		printf("Failed to open the bus.");
		exit(1);
	}
}

// Public Methods //////////////////////////////////////////////////////////////

void TwoWire::begin(void)
{
  rxBufferIndex = 0;
  rxBufferLength = 0;
  txBufferIndex = 0;
  txBufferLength = 0;
}

void TwoWire::begin(uint8_t address)
{
	if (ioctl(this->fd,I2C_SLAVE,address) < 0) {
		printf("Failed to acquire bus access and/or talk to slave.\n");
	}

  begin();
}

void TwoWire::begin(int address)
{
  begin((uint8_t)address);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{

      if (ioctl(this->fd,I2C_SLAVE,address) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
        }


  if(quantity > BUFFER_LENGTH){
    quantity = BUFFER_LENGTH;
  }

  uint8_t read = ::read(fd,&rxBuffer,quantity);
  rxBufferIndex = 0;
  rxBufferLength = read;

  return read;
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}

uint8_t TwoWire::requestFrom(int address, int quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}

uint8_t TwoWire::requestFrom(int address, int quantity, int sendStop)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)sendStop);
}

void TwoWire::beginTransmission(uint8_t address)
{
      if (ioctl(this->fd,I2C_SLAVE,address) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
        }


  // indicate that we are transmitting
  transmitting = 1;
  // set address of targeted slave
  txAddress = address;
  // reset tx buffer iterator vars
  txBufferIndex = 0;
  txBufferLength = 0;
}

void TwoWire::beginTransmission(int address)
{
  beginTransmission((uint8_t)address);
}

uint8_t TwoWire::endTransmission(uint8_t sendStop)
{
  return 1;
}

uint8_t TwoWire::endTransmission(void)
{
  return endTransmission(true);
}

size_t TwoWire::write(uint8_t data)
{
  ::write(fd,&data,1);
  return 1;
}

size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
  ::write(fd,data,quantity);
  return quantity;
}

int TwoWire::available(void)
{
  return rxBufferLength;
}

int TwoWire::read(void)
{
  int value = -1;
  if(rxBufferLength>0){
    value=rxBuffer[rxBufferIndex++];
    rxBufferLength--;
  }
  return value;
}

int TwoWire::peek(void)
{
  int value = -1;
  
  if(rxBufferLength>0){
    value = rxBuffer[rxBufferIndex];
  }

  return value;
}

void TwoWire::flush(void)
{
  // XXX: to be implemented.
}





TwoWire Wire = TwoWire();

