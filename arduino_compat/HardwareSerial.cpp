
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
        
        if(bytes_available>0)printf("serial.avail %d\r\n",bytes_available);
	return bytes_available;
}


int HardwareSerial::peek(void)
{
    printf("serial.peek\r\n");
    return -1;
}

uint8_t buf[2048];

int HardwareSerial::read(void)
{

	::read(fd,buf,2048);
  
//   tcflush(fd,TCIOFLUSH);

   printf("serial.read '%c'\r\n",buf[0]);
   return buf[0];
}

void HardwareSerial::flush()
{
   printf("serial.flush\r\n");
}

size_t HardwareSerial::write(uint8_t c)
{
  ::write(fd,&c,1);
//tcflush(fd,TCIOFLUSH);

  return 1;
}

HardwareSerial::operator bool() {
	return true;
}

void HardwareSerial::socat_link(const char* dev){
	printf("serial.socat_link %s\r\n",dev);

      fd = open( dev, O_RDWR| O_NOCTTY );

    struct termios tty;
struct termios tty_old;
memset (&tty, 0, sizeof tty);

/* Error Handling */
if ( tcgetattr (fd, &tty ) != 0 )
{
  perror(dev); exit(1);
}

/* Save old tty parameters */
tty_old = tty;

/* Set Baud Rate */
cfsetospeed (&tty, (speed_t)B115200);
cfsetispeed (&tty, (speed_t)B115200);

/* Setting other Port Stuff */
tty.c_cflag     &=  ~PARENB;        // Make 8n1
tty.c_cflag     &=  ~CSTOPB;
tty.c_cflag     &=  ~CSIZE;
tty.c_cflag     |=  CS8;

tty.c_cflag     &=  ~CRTSCTS;       // no flow control
tty.c_cc[VMIN]      =   1;                  // read doesn't block
tty.c_cc[VTIME]     =   5;                  // 0.5 seconds read timeout
tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

/* Make raw */
cfmakeraw(&tty);

/* Flush Port, then applies attributes */
tcflush( fd, TCIFLUSH );
if ( tcsetattr ( fd, TCSANOW, &tty ) != 0)
{
  perror(dev); exit(1);
}                                   
                                                                                
                                               

}

HardwareSerial::HardwareSerial(){

}

HardwareSerial Serial;

