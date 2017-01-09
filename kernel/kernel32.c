/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/
#include "mos_kernel32_basic.h"
void kmain() // Kernel's main entry point.
{
	char string1[21] = "Kernel>MOS's kernel loaded !";
	char string2[39] = "Kernel>Actual MOS's kernel version is  ";
	string2[39] = MOS_
	char string3[32] = "Kernel>MOS is waiting for something ...";
	clearScreen(); // Clear the screen.
	printGreenString(0,0,string1,21);
	printWhiteString(0,1,string2,32);	
	while(1){}; // Infinite loop.
}
