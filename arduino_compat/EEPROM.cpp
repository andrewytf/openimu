/*
  EEPROM.cpp - EEPROM library
  Copyright (c) 2006 David A. Mellis.  All right reserved.

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
*/

/******************************************************************************
 * Includes
 ******************************************************************************/


//#include <avr/eeprom.h>
#include "Arduino.h"
#include "EEPROM.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * Constructors
 ******************************************************************************/

/******************************************************************************
 * User API
 ******************************************************************************/

uint8_t mem[2048];

uint8_t EEPROMClass::read(int address)
{

//	return (unsigned char *) address);
	printf("eeprom.read addr=%x value=%x\r\n",address,mem[address]);
	return mem[address];
}

void EEPROMClass::write(int address, uint8_t value)
{
	printf("eeprom.wrte addr=%x value=%x\r\n",address,value);
	mem[address]=value;
	//eeprom_write_byte((unsigned char *) address, value);
}

EEPROMClass EEPROM;
