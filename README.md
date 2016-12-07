# MOS Operating System
This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](https://creativecommons.org/licenses/by-nc-sa/4.0/).</br>
**MOS** is currently in development.</br>
The reading of this [PDF](http://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf) is strongly recommended.
# What is MOS ?
MOS is the acronyme for **Minimalist Operating System**.</br>
You can find all the **MOS** sources in this **repository**.</br>
**MOS** is targeted to [8086 family intel processors](https://en.wikipedia.org/wiki/Intel_8086).</br>
# Advantages and Disadvantages
**MOS**'s meaning is to be fully customizable, from the bootloader to the kernel.</br>
You can modify **MOS** from itself or from the sources.</br>
For the moment, **MOS** is designed for the developer, don't download this OS for your grandma.</br>
There is currenty no OpenGL support, so forget (or develop?) the 3D games.</br>
It's better to install **MOS** on a USB key (with sector size of 512 octets).</br>
# How to modify MOS from the sources and build it
## Example : Compile the bootloader
Download all the **bootloader** directory, modify it and build it with nasm.
```batch
nasm.exe -f bin main.asm -o bootloader.bin
```
You now have your MOS bootloader compiled.
## Example : Install the bootloader
Now, let's say you want to copy the bootloader on a USB key.</br>
With **ADMIN rights**, type in a console :
```batch
dd if=bootloader.bin of=f: count=1 bs=512 seek=0
```
If you have to copy binary code on the third sector (for example), you must write :
```batch
dd if=binaryCODE.bin of=f: count=1 bs=512 seek=2
```
## Example : Compile the kernel and install it
It's the same as the **bootloader**, download the **kernel** folder, modify it, compile the **kernelMain.asm** file.
```batch
nasm -f bin kernelMain.asm -o kernel.bin
```
Then you just need to install it on whatever you like, like the bootloader.
```batch
dd if=kernel.bin od=f: count=COUNT bs=512 seek=SECTOR_NUMBER
```
