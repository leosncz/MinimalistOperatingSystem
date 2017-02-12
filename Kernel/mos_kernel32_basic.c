/*
File: mos_kernel32_basic.c
Author: leosncz
Purpose:
This file contains datas and functions the kernel might uses.
*/
#ifndef MOS_KERNEL32_BASIC
#define MOS_KERNEL32_BASIC
#define MOS_KERNEL_VERSION "ALPHA" // Must contains five characters. For example if version is 1.0 : #define MOS_KERNEL_VERSION "1.000"
#define DEBUG_MODE 0x0
#define RELEASE_MODE 0x1
#define DEV_STATUS DEBUG_MODE // You'll have to change it later to RELEASE_MODE.
#include "mos_graphics_vga_mode.c" 
#endif
