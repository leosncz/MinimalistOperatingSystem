# MOS Operating System
This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](https://creativecommons.org/licenses/by-nc-sa/4.0/).</br>
**MOS** is currently in development.
# What is MOS ?
MOS is the acronyme for **Minimalist Operating System**.</br>
You can find all the **MOS** sources in this **repository**.</br>
**MOS** is targeted to [x86 intel processors](https://en.wikipedia.org/wiki/X86).</br>
# Advantages and Disadvantages
**MOS**'s meaning is to be fully customizable, from the bootloader to the kernel.</br>
You can modify **MOS** from itself or from the sources.</br>
For the moment, **MOS** is designed for the developer, don't download this OS for your grandma.</br>
There is currenty no OpenGL support, so forget (or develop?) the 3D games.</br>
It's better to install **MOS** on a USB key (with sector size of 512 octets).</br>
# How to modify MOS from the sources and build it
Download all the **bootloader** directory, modify it and build it with nasm.
```batch
nasm.exe -f bin main.asm -o bootloader.bin
```
You now have your MOS bootloader compiled.</br>
It's the same for everything else.</br>
Example command using **dd** for installing a **bootloader** and a **second sector** on a USB key :
```batch
dd if=bootloader.bin of=f: count=1 bs=512 seek=0
dd if=secondSec.bin of=f: count=1 bs=512 seek=1
```
The included file in **main.asm** must be in the same directory.</br>



