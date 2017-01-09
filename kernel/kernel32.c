/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/
#include "mos_kernel32_basic.h"
void kmain() // Kernel's main entry point.
{
	char string1[28] = "Kernel>MOS's kernel loaded !";
	char string2[39] = "Kernel>Actual MOS's kernel version is  ";
	string2[39] = MOS_KERNEL_VERSION;
	char string3[39] = "Kernel>MOS is waiting for something ...";
	clearScreen(); // Clear the screen.
	printGreenString(0,0,string1,21);
	printGreenString(0,1,string2,39);
	printWhiteString(0,1,string3,32);	
	while(1){}; // Infinite loop.
}
