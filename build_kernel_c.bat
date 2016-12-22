gcc -ffreestanding -c kernel.c -o kernel.o
ld -T NUL -o kernel.tmp -Ttext 0x7e00 kernel.o
objcopy -O binary -j .text  kernel.tmp kernel.bin
del kernel.o
del kernel.tmp
