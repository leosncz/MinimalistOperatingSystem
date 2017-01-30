/*
File: mos_graphics_vga_mode.c
Author: leosncz
Purpose:
ONLY VGA MODE graphics stuff.
*/
#ifndef MOS_GRAPHICS_VGA_MODE
#define MOS_GRAPHICS_VGA_MODE
#include "mos_low_level.c"
void writePixelVGA_test()
{
    unsigned char* location = (unsigned char*)0x0A0000;
    writeByteToMemory(0xF,location);
    writeByteToMemory(0xF,location+1);
    writeByteToMemory(0xF,location+2);
    writeByteToMemory(0xF,location+3);
}
#endif
