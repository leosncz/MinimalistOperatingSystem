/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/
#include "mos_kernel32_basic.c"
void kmain() // Kernel's main entry point.
{
	/* 
	We are in VGA Mode (NOT IN TEXT MODE !).
	The VGA mode has been set up by our bootloader.
	*/
	writePixelVGA(0,0,VGA_COLOR_WHITE); // Print a pixel to prove the kernel is loaded.
	while(1){}; // Infinite loop (so it does not execute other things).
}
