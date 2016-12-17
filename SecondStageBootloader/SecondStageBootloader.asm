; Second Stage Bootloader of MOS Operating System.
; Check the license at GitHub.com/leosncz/OperatingSystem/
; NASM syntax.
[org 0x1000]

jmp main
%include "resources.asm"
main:
mov si, loadedMSG
call printIntPrepareNL
call printInt
jmp $

loadedMSG: db "MOS Second Stage Bootloader loaded !", 0
