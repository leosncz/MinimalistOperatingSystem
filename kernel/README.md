# Minimalist Operating System (MOS) Kernel
## How does it work ?
**kernel_entry.asm** loads the **kmain** function in **kernel32.c**.</br>
You can compile and link everything with the **build_kernel_c.bat** script.</br>
After compiling and linking you probably got a **kernel32.bin** file, it must be located on the second sector of the disk (loaded by the bootloader).

