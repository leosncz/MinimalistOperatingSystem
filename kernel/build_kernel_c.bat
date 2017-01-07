nasm kernel_entry.asm -f elf -o kernel_entry.o
gcc -ffreestanding -c kernel32.c -o kernel32.o
ld -T NUL -o kernel32.tmp -Ttext 0x7e00 kernel_entry.o kernel32.o
objcopy -O binary -j .text  kernel32.tmp kernel32.bin
del kernel32.tmp
del kernel32.o
del kernel_entry.o
pause
