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
mov bl, 0010b ; Binary expressed color of the text.
mov cx, 1d;
mov ah, 0x9
mov al, [si]
cmp al, 0
je endPrintInt
int 0x10
inc si
inc dl ; Add a row.
jmp printInt
endPrintInt:
ret

printIntPrepareNL: ; Add new line.
inc dh
mov dl, 0d
ret

; Datas :
bootDriveNumber: db 0d ; Boot drive number ID.
text1: db "Minimalist Operating System (MOS) ALPHA bootloader", 0
text2: db "Jumping into hyperspace (PMode in fact ...)", 0
