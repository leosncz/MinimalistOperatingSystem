; Bootloader of MOS Operating System.
; NASM syntax.
[org 0x7C00]
jmp main
%include "func.asm" ; Contains usefull functions.
main:
jmp $ ;Loop.
times 510 - ($-$$) db 0 ; Must be 512 size.
db 0x55 ; Magical Number.
db 0xAA ; Magical Number.
