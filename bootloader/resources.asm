; Real Mode datas of MOS Operating System.
; Check the license at GitHub.com/leosncz/OperatingSystem/
; NASM syntax.

; Functions :
init:
mov [bootDriveNumber], dl ; Save boot drive number id.
xor ax, ax
mov dx, ax
ret

printInt: ; Print the SI register to the screen.
mov ah, 0x2
mov bh, 0x0
int 0x10
mov bl, 0100b
mov cx, 1d;
mov ah, 0x9
mov al, [si]
cmp al, 0
je finPrintInt
int 0x10
inc si
inc dl ; Add a row.
jmp printInt
finPrintInt:
ret

printIntPrepareNL: ; Add new line.
inc dh
mov dl, 0d
ret

; Datas :
bootDriveNumber: db 0d ; Boot drive number ID.
text1: db "MOS Bootloader loaded at 0x0:0x7C00", 0
