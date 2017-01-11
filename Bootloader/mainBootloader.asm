; Bootloader of MOS Operating System.
; NASM syntax.
[org 0x7C00]
xor ax, ax
mov ds, ax
mov es, ax
mov ss, ax
mov bp, ax
mov ax, 0x7C00 ; Stack --> 0x0:0x7C00
mov sp, ax
jmp main
%include "UTIL.inc" ; Contains usefull datas.
main:
call init ; Init resources.asm functions.
mov si, text1
call printInt
call printIntPrepareNL
mov si, text2
call printInt
call printIntPrepareNL
call load2ndSector ; Loads kernel.
mov si, text3
call printInt
call setupGDT ; Setup GDT and PMode.
; Now we are in PMode.
jmp 0x8:startPMode
[bits 32]
startPMode:
mov ax , DATA_SEG ; Now in PM , our old segments are meaningless ,
mov ds , ax ; so we point our segment registers to the
mov ss , ax ; data selector we defined in our GDT
mov es , ax
mov ebp , 0x90000 ; Update our stack position so it is right
mov esp , ebp ; at the top of the free space.
call 0x8:0x7e00 ; Jump to the kernel
jmp $  ; If MOS's kernel give back the control, it won't break anything.
times 510 - ($-$$) db 0 ; Must be 512 size.
dw 0xAA55 ; Magical number.
