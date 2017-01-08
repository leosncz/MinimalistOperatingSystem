/*
File: mos_kernel32_basic.h
Author: leosncz
Purpose:
This file contains datas and functions the kernel might uses.
*/

#define RAMSCREEN 0xB8000 // Video address.
void printWhiteCharacter(char colX, char rowY, char characterToPrint) // It prints a white character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)0xB8000+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(0xB8000+2*(rowY*80+colX))+1;
	*video=0xF; // White on black attribute.
}

void printRedCharacter(char colX, char rowY, char characterToPrint) // It prints a red character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)0xB8000+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(0xB8000+2*(rowY*80+colX))+1;
	*video=0xC; // Red on black attribute.
}

void printGreenCharacter(char colX, char rowY, char characterToPrint) // It prints a green character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)0xB8000+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(0xB8000+2*(rowY*80+colX))+1;
	*video=0xA; // Green on black attribute.
}


