/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/
#include "mos_kernel32_basic.c"
void kmain() // Kernel's main entry point.
{
	clearScreen(); // Clear the bootloader outputs.
	char string1[31] = "[KERNEL LOG]MOS Kernel loaded !";
	char string2[30] = "[KERNEL LOG]Kernel version is ";
	char string3[5] = MOS_KERNEL_VERSION;
	char string4[47] = "[KERNEL LOG]Kernel is waiting for something ...";
	kernelOutputGreenString(0,0,string1,31);
	kernelOutputGreenString(0,1,string2,30);
	kernelOutputRedString(30,1,string3,5);
	kernelOutputWhiteString(0,2,string4,47);
	while(1){}; // Infinite loop (so it does not execute garbage).
}
