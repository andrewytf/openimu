
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

#include "HardwareSerial.h"

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
#include <fcntl.h>  /* File control definitions */
#include <unistd.h> /* UNIX standard function definitions */
#include <sys/time.h>
#include <termios.h> /* POSIX terminal control definitions */

void HardwareSerial::begin(unsigned long baud)
{
}

void HardwareSerial::begin(unsigned long baud, byte config)
{
}

void HardwareSerial::end()
{
}

int HardwareSerial::available(void)
{
	int bytes_available;
	ioctl(fd, FIONREAD, &bytes_available);
	return bytes_available;
}

int HardwareSerial::peek(void)
{
    return -1;
}

int HardwareSerial::read(void)
{
	uint8_t value;
	if( ::read(fd,&value,1) == 1){
		return value;
	} else {
	    return -1;
	}
}

void HardwareSerial::flush()
{

}

size_t HardwareSerial::write(uint8_t c)
{
  ::write(fd,&c,1);
  return 1;
}

HardwareSerial::operator bool() {
	return true;
}

void HardwareSerial::socat_link(char* dev){
	printf("serial.socat_link %s\r\n",dev);
	if ((this->fd = open(dev,O_RDWR|O_NOCTTY|O_NDELAY)) < 0) {
		printf("Failed to open the bus.");
		exit(1);
	}
	fcntl(fd,F_SETFL,0);

struct termios options;

//get attributes
tcgetattr(fd, &options);

//cfsetispeed(&options, B19200);
//cfsetospeed(&options, B19200);

//configure for raw input (not wait for enter)
options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

//set attributes
tcsetattr(fd, TCSANOW, &options);


}

HardwareSerial::HardwareSerial(){

}

HardwareSerial Serial;

