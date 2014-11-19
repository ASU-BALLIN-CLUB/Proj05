//
//  uart.c
//
//	Proj05
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#include "uart.h"


void uart_init()
{
	MCF_UART_UMR11 = 0x0;
	MCF_UART_UMR11 = 0b00001011;
	MCF_UART_UMR21 = 0x0;
	MCF_UART_UMR21 = 0b00000001;

}

void uart_begin()
{

}
