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
	for(int i=0;i<5;i++)
	{
		writePixelVGA(0,i,VGA_COLOR_RED);
	}
	for(int i=5;i<10;i++)
	{
		writePixelVGA(0,i,VGA_COLOR_GREEN);
	}
	for(int i=10;i<15;i++)
	{
		writePixelVGA(0,i,VGA_COLOR_WHITE);
	}
	for(int i=15;i<20;i++)
	{
		writePixelVGA(0,i,VGA_COLOR_GREY);
	}
	while(1){}; // Infinite loop (so it does not execute other things).
}
