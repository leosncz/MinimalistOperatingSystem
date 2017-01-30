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
	The VGA mode has been set by the bootloader.
	Let's print some pixel to prove that the kernel has been loaded.
	*/
	writePixelVGA(0,0,VGA_COLOR_RED);
	writePixelVGA(0,1,VGA_COLOR_GREEN);
	writePixelVGA(0,2,VGA_COLOR_WHITE);
	writePixelVGA(0,3,VGA_COLOR_RED);
	writePixelVGA(0,4,VGA_COLOR_GREEN);
	writePixelVGA(0,5,VGA_COLOR_WHITE);
	while(1){}; // Infinite loop (so it does not execute other things).
}
