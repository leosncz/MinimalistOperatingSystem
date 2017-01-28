/*
File: mos_kernel32_basic.c
Author: leosncz
Purpose:
This file contains datas and functions the kernel might uses.
*/
#define RAMSCREEN 0xB8000 // Video address.
#define MOS_KERNEL_VERSION "ALPHA" // Must contains five characters. For example if version is 1.0 : #define MOS_KERNEL_VERSION "1.000"
#include "mos_low_level.c" // Contains low level functions.
#include "mos_graphics_text_mode.c"
