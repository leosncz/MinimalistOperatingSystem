/*
File: mos_kernel32_basic.c
Author: leosncz
Purpose:
This file contains datas and functions the kernel might uses.
*/
#define RAMSCREEN 0xB8000 // Video address.
#define MOS_KERNEL_VERSION "ALPHA" // Must contains five characters. For example if version is 1.0 : #define MOS_KERNEL_VERSION "1.000"
#include "mos_low_level.c" // Contains low level functions.

void updateCursor(int row, int col) // Update the blinking cursor.
{
	unsigned short position=(row*80) + col;
	outb(CRT_PORT_INDEX,0x0F); // We wanna modify low part of cursor's position.
	outb(CRT_PORT_DATA,(unsigned char)(position&0xFF)); // We modify low part.
	outb(CRT_PORT_INDEX,0x0E); // We wanna modify high part of cursor's position.
	outb(CRT_PORT_DATA,(unsigned char )((position>>8)&0xFF)); // We modify high part.
}

void kernelOutputWhiteCharacter(char colX, char rowY, char characterToPrint) // It prints a white character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(RAMSCREEN+2*(rowY*80+colX))+1;
	*video=0xF; // White on black attribute.
	updateCursor(rowY,colX);
}

void kernelOutputRedCharacter(char colX, char rowY, char characterToPrint) // It prints a red character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(RAMSCREEN+2*(rowY*80+colX))+1;
	*video=0xC; // Red on black attribute.
	updateCursor(rowY,colX);
}

void kernelOutputGreenCharacter(char colX, char rowY, char characterToPrint) // It prints a green character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(RAMSCREEN+2*(rowY*80+colX))+1;
	*video=0xA; // Green on black attribute.
	updateCursor(rowY,colX);
}

void kernelOutputGreenString(char colX, char rowY, char string[],int size) // It prints a green string.
{
	char colX_ = colX;
	char rowY_ = rowY;
	for(int i=0;i<size;i++)
	{
		kernelOutputGreenCharacter(colX_,rowY_,string[i]);
		colX_++;
	}
}

void kernelOutputWhiteString(char colX, char rowY, char string[],int size) // It prints a white string.
{
	char colX_ = colX;
	char rowY_ = rowY;
	for(int i=0;i<size;i++)
	{
		kernelOutputWhiteCharacter(colX_,rowY_,string[i]);
		colX_++;
	}
}

void kernelOutputRedString(char colX, char rowY, char string[],int size) // It prints a red string.
{
	char colX_ = colX;
	char rowY_ = rowY;
	for(int i=0;i<size;i++)
	{
		kernelOutputRedCharacter(colX_,rowY_,string[i]);
		colX_++;
	}
}

void kernelOutputGreenLine(char colX,char rowY, int width)
{
	int i = 0;
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	while(i!=width)
	{
		*video=' ';
		video++;
		*video=0x2A; // Green on green attribute.
		updateCursor(rowY,colX);
		i=i+1;
		video++;
	}
}

void kernelOutputRedLine(char colX,char rowY, int width)
{
	int i = 0;
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	while(i!=width)
	{
		*video=' ';
		video++;
		*video=0x4C; // Red on red attribute.
		updateCursor(rowY,colX);
		i=i+1;
		video++;
	}
}

void kernelOutputWhiteLine(char colX,char rowY, int width)
{
	int i = 0;
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	while(i!=width)
	{
		*video=' ';
		video++;
		*video=0x7F; // White on white attribute.
		updateCursor(rowY,colX);
		i=i+1;
		video++;
	}
}

void clearScreen() // It clears the screen.
{
	unsigned char *video = (unsigned char*)RAMSCREEN;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		video[i]=' '; // Nothing (space).
		i++;
		video[i]=0xF; // White on black attribute.
		i++;
	}
}
