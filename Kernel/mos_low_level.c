/*
File: low_level.c
Author: leosncz
Purpose:
Contains low level functions.
*/
void outb(unsigned int portToWrite,unsigned char whatToPrint)
{
  asm volatile("outb %%al,%%dx": :"d" (portToWrite), "a" (whatToPrint));
}

inline unsigned char inb(unsigned int portToRead)
{
  unsigned char ret;
  asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
  return ret;
}
