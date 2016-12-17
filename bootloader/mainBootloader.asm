; Bootloader of MOS Operating System.
; Check the license at GitHub.com/leosncz/OperatingSystem/
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
%include "resources.asm" ; Contains usefull datas.
main:
call init ; Init resources.asm functions.
mov si, text1
call printInt
call printIntPrepareNL
mov si, text2
call printInt
jmp $ ;Loop.
times 510 - ($-$$) db 0 ; Must be 512 size.
db 0x55 ; Magical Number.
db 0xAA ; Magical Number.
