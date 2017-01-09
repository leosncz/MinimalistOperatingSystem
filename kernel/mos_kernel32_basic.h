/*
File: mos_kernel32_basic.h
Author: leosncz
Purpose:
This file contains datas and functions the kernel might uses.
*/
#define RAMSCREEN 0xB8000 // Video address.

void printWhiteCharacter(char colX, char rowY, char characterToPrint) // It prints a white character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(RAMSCREEN+2*(rowY*80+colX))+1;
	*video=0xF; // White on black attribute.
}

void printRedCharacter(char colX, char rowY, char characterToPrint) // It prints a red character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(RAMSCREEN+2*(rowY*80+colX))+1;
	*video=0xC; // Red on black attribute.
}

void printGreenCharacter(char colX, char rowY, char characterToPrint) // It prints a green character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(RAMSCREEN+2*(rowY*80+colX))+1;
	*video=0xA; // Green on black attribute.
}

void printGreenString(char colX, char rowY, char string[],int size) // It prints a green string.
{
	char colX_ = colX;
	char rowY_ = rowY;
	for(int i=0;i<size;i++)
	{
		printGreenCharacter(colX_,rowY_,string[i]);
		colX_++;
	}
}

void printWhiteString(char colX, char rowY, char string[],int size) // It prints a white string.
{
	char colX_ = colX;
	char rowY_ = rowY;
	for(int i=0;i<size;i++)
	{
		printWhiteCharacter(colX_,rowY_,string[i]);
		colX_++;
	}
}

void printRedString(char colX, char rowY, char string[],int size) // It prints a red string.
{
	char colX_ = colX;
	char rowY_ = rowY;
	for(int i=0;i<size;i++)
	{
		printRedCharacter(colX_,rowY_,string[i]);
		colX_++;
	}
}

void clearScreen() // It clears the screen.
{
	unsigned char *video = (unsigned char*)RAMSCREEN;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		video[i]=' ';
		i++;
		video[i]=0xF; // White on black attribute.
		i++;
	}
}
