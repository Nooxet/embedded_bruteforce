/*
 * Copyright (c) 2009 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/*
 * helloworld.c: simple test application
 */

#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xuartlite_l.h"
//#include "xgpio.h"
//#include "xil_io.h"
#include "mb_interface.h"

#define LEDS_BASEADDR XPAR_LEDS_8BITS_BASEADDR
#define SW_BASEADDR XPAR_DIP_SWITCHES_8BITS_BASEADDR
#define BTN_BASEADDR XPAR_PUSH_BUTTONS_4BITS_BASEADDR

void print(char *str);

int main()
{
    init_platform();

    while (1) {
		char recv = XUartLite_RecvByte(STDIN_BASEADDRESS);
		unsigned num = 0;

		while (recv >= '0' && recv <= '9') {
			num = num*10 + (recv-'0');
			recv = XUartLite_RecvByte(STDIN_BASEADDRESS);
		}

		putfsl(num, 0);

		char resp;
		getfsl(resp, 0);

		xil_printf("ans: %d", resp);
    }
    cleanup_platform();

    return 0;
}
