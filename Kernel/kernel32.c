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
	char string2[39] = "Kernel>MOS is waiting for something ...";
	kernelOutputGreenString(0,3,string1,28);
	kernelOutputBasicInfos(4);
	kernelOutputWhiteString(0,5,string2,39);
	while(1){}; // Infinite loop.
}
