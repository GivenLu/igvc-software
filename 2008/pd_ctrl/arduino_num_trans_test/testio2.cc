//#include <cstdlib>
//#include <stdint.h>   /* Standard types */
//#include <string.h>   /* String function definitions */
#include <unistd.h>   /* UNIX standard function definitions */
//#include <fcntl.h>    /* File control definitions */
//#include <termios.h>  /* POSIX terminal control definitions */
//#include <sys/ioctl.h>
//#include <getopt.h>
//#include <stdbool.h>
#include <cstdio>    /* Standard input/output definitions */
#include <errno.h>    /* Error number definitions */
//#include <time.h>
//#include <cmath>
//#include <iostream>

#include <assert.h>

#include "arduino_comm.h"
#include "arduino_readnum.h"

#define SERIALPORT "/dev/ttyUSB0"
#define BAUD B9600



int main(void){

	char buffer[10] = {0};
	char f[2] = "f";
	char b[2] = "b";
	char u[2] = "u";
	int arduino_fd = serialport_init(SERIALPORT, BAUD);
	assert(arduino_fd != -1);

	printf("a short int is %u bytes long\n",sizeof(short int));

	float xfer_f;
	xfer_f = readFloat(arduino_fd, f, buffer);
	printf("rec float: %f\n", xfer_f);
	
	short int xfer_si;
	xfer_si = readSint16(arduino_fd, b, buffer);
	printf("rec sint16: %d\n", xfer_si);

	unsigned short int xfer_usi;
	xfer_usi = readUint16(arduino_fd, u, buffer);
	printf("rec uint16: %d\n", xfer_usi);


}
