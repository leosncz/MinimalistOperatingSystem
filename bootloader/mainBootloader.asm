; Bootloader of MOS Operating System.
; Check the license at GitHub.com/leosncz/OperatingSystem/
; NASM syntax.
; This code loads in memory the second and third sectors at 0x0:0x1000 (real mode addressing).
[org 0x7C00]
jmp main
%include "resources.asm" ; Contains usefull datas.
main:
jmp $ ;Loop.
times 510 - ($-$$) db 0 ; Must be 512 size.
db 0x55 ; Magical Number.
db 0xAA ; Magical Number.
