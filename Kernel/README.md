# Minimalist Operating System (MOS) Kernel
## How does it work ?
**kernel_entry.asm** execute the **kmain** function located in **kernel32.c**.</br>
You can compile and link everything with the **build_kernel_c.bat** script.</br>
After running this script, you should have a file called **kernel32.bin**, it is supposed to be loaded by the bootloader, on the second sector of a **USB key**.

