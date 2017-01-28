/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/
#include "mos_kernel32_basic.h"
void kmain() // Kernel's main entry point.
{
	char string1[27] = "MOS_Kernel> Kernel loaded !";
	char string2[30] = "MOS_Kernel> Kernel version is ";
	char mosKernelVersion[5] = MOS_KERNEL_VERSION;
	char string3[44] = "MOS_Kernel> MOS is waiting for something ...";
	clearScreen(); // Clear the screen.
	// Print ...
	kernelOutputGreenString(0,0,string1,27);
	kernelOutputGreenString(0,1,string2,30);
	kernelOutputRedString(30,1,mosKernelVersion,5);
	kernelOutputGreenString(0,2,string3,44);
	while(1){}; // Infinite loop.
}
