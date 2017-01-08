/*
File: mos_kernel32_basic.h
Author: leosncz
Purpose:
This file contains datas and functions the kernel might uses.
*/
#define RAMSCREEN 0xB8000 // Video address.
void printRedCharacter(unsigned char characterToPrint)
{
unsigned char *video = (unsigned char*)0xB8000;
video=(unsigned char*)0xB8000;
unsigned char character = characterToPrint;
*video=character;
video = (unsigned char*)0xB8001;
*video = 0xC;
}

