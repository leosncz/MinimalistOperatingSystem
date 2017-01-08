/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/
#include "mos_kernel32_basic.h"
void kmain()
{
unsigned char character = 'A';
printRedCharacter(character);
while(1){}; // Infinite loop.
}
