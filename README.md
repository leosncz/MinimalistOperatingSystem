# MOS Operating System
This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](https://creativecommons.org/licenses/by-nc-sa/4.0/).</br>
**MOS** is currently in development.</br>
The reading of this [PDF](http://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf) is strongly recommended.
## What is MOS ?
MOS is the acronyme for **Minimalist Operating System**.</br>
You can find all the **MOS** sources in this **repository**.</br>
**MOS** is targeted to [8086 family intel processors](https://en.wikipedia.org/wiki/Intel_8086).</br>
## Advantages and Disadvantages
**MOS**'s meaning is to be fully customizable, from the bootloader to the kernel.</br>
You can modify **MOS** from itself or from the sources.</br>
For the moment, **MOS** is designed for developers, don't install this OS on your grandma's computer.</br>
## Tools
To edit files and disks, i really like to use [DD](https://fr.wikipedia.org/wiki/Dd_(Unix)), it's powerfull.</br>
If you're under Windows, you can use [HxD editor](https://mh-nexus.de/en/hxd/), it's as powerfull as **DD**.</br>
I used [nasm](http://www.nasm.us/) to produce binary code, all the assembler parts of **MOS** are written in **nasm** syntax.</br>
Of course, [gcc](http://www.mingw.org/) suite (Windows version) is needed in order to compile and link everything.</br>
To finish with, I also like [QEMU](http://wiki.qemu.org/Main_Page) to test binary codes.
## File encoding
**NASM** require **utf-8 without BOM**.
## Version
**Bootloader : ALPHA**</br>
**Kernel : ALPHA**
## Environment variables
To run all the provided **.bat** scripts, you MUST add **nasm, dd and gcc's directory** to the **PATH** environment variable.
