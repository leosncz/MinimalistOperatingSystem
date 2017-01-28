/*
File: low_level.c
Author: leosncz
Purpose:
Contains low level functions.
*/
#define CRT_PORT_DATA 0x3D4
#define CRT_PORT_INDEX 0x3D5
void outb(unsigned int portToWrite, unsigned char whatToPrint)
{
  asm volatile("outb %%al,%%dx": :"d" (portToWrite), "a" (whatToPrint));
}

inline unsigned char inb(unsigned int portToRead)
{
  unsigned char ret;
  asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (portToRead));
  return ret;
}
