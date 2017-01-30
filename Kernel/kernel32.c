/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/
#include "mos_kernel32_basic.c"
void kmain() // Kernel's main entry point.
{
	// We are in VGA Mode.
	// do whatever you want ...
	while(1){}; // Infinite loop (so it does not execute other things).
}
