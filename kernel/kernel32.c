/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/

#include "mos_kernel32_basic.h"
void kmain() // Kernel's main entry point.
{
	char string1[21] = "MOS's kernel loaded !";
	char string2[32] = "MOS is waiting for something ...";
	clearScreen();
	printGreenString(0,0,string1,21);
	printWhiteString(0,1,string2,32);	
	while(1){}; // Infinite loop.
}
