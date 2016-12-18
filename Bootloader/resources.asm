; Real Mode things of MOS Operating System.
; Check the license at GitHub.com/leosncz/OperatingSystem/
; NASM syntax.
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
mov cx, 1d
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

load2nd3rdSector: ; Load Second stage bootloader at 0x0:0x1000.
push ax
push dx
xor ax,ax
mov es, ax
mov ax, 0x1000
mov bx, ax
mov dl, [bootDriveNumber]
mov ah, 0x0
int 0x13
mov ah, 0x2
mov al, 2d ; Read 2 sectors(2-->3).
mov ch, 0x0
mov cl, 2d ; Load from second sector.
mov dh, 0x0
int 0x13
pop dx
pop ax
ret

bootDriveNumber: db 0d ; Boot drive number ID.
text1: db "Minimalist Operating System (MOS) ALPHA bootloader", 0
text2: db "Loading Second stage bootloader at 0x0:0x1000 ...", 0
text3: db "Second Stage Loaded !", 0
text4: db "Jumping into hyperspace (PMode in fact ...)", 0
