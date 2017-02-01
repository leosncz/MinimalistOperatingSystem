/*
File: mos_graphics_vga_mode.c
Author: leosncz
Purpose:
ONLY VGA MODE graphics stuff.
*/
#ifndef MOS_GRAPHICS_VGA_MODE
#define MOS_GRAPHICS_VGA_MODE
#include "mos_low_level.c"
// Define some colors.
#define VGA_COLOR_BLACK 0x0
#define VGA_COLOR_RED 0x28
#define VGA_COLOR_GREEN 0x2F
#define VGA_COLOR_WHITE 0xF
#define VGA_COLOR_GREY 0x18
/*
There are 256 colors in total(one byte), feel free to add some colors if you want.
In VGA mode, the top-left corner represents I(0;0).
*/
void writePixelVGA(char x, char y, char color)
{
    unsigned char* location = (unsigned char*)0x0A0000; // This is the base address.
    writeByteToMemory(color,location + ((320*y) + x));
}

void writeHorizontalLineVGA(char x, char y, char sizeX, char color)
{
    for(int i=x;i<sizeX;i++)
    {
        writePixelVGA(x,y,color); // Write the pixel.
	x++; // Increment.
    }
}

void writeVerticalLineVGA(char x, char y, char sizeY, char color) // I haven't tested it yet.
{
    for(int i=y;i<sizeY;i++)
    {
        writePixelVGA(x,y,color); // Write the pixel.
	y++; // Increment.
    }
}

void writeSquareVGA(char x, char Y, char sizeXnY, char color) // It's a square so X=Y.
{
	// To do ...
}
#endif
