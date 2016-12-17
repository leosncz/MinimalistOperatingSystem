; Kernel of MOS Operating System.
; Check the license at GitHub.com/leosncz/OperatingSystem/
; NASM syntax.
; This is the first code loaded by the bootloader on the second sector.
[org 0x1000]
mov ah, 0x0E
mov al, [letterX]
int 0x10
jmp $

letterX: db "X"
