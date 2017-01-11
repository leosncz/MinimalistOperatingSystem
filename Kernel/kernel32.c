/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/
#include "mos_kernel32_basic.h"
void printInitMessages() // Print basic infos.
{
	char string1[28] = "Kernel>MOS's kernel loaded !";
	char string2[31] = "Kernel>MOS's kernel version is ";
	char mosKernelVersion[5] = MOS_KERNEL_VERSION;
	char string3[39] = "Kernel>MOS is waiting for something ...";
	kernelOutputGreenString(0,3,string1,28);
	kernelOutputGreenString(0,4,string2,31);
	kernelOutputRedString(31,4,mosKernelVersion,5);
	kernelOutputGreenString(0,5,string3,39);
}
void kmain() // Kernel's main entry point.
{
	printInitMessages();
	while(1){}; // Infinite loop.
}
