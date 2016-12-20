; Usefull things of MOS Operating System.
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
mov bl, 1111b ; Binary expressed color of the text.
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

load2ndSector: ; Load Second stage bootloader.
push ax
push dx
xor ax,ax
mov es, ax
mov ax, 0x7e00
mov bx, ax
mov dl, [bootDriveNumber]
mov ah, 0x0
int 0x13
mov ah, 0x2
mov al, 100d ; Read 100 sectors.
mov ch, 0x0
mov cl, 2d ; Load from second sector.
mov dh, 0x0
int 0x13
pop dx
pop ax
ret

bootDriveNumber: db 0d ; Boot drive number ID.
text1: db "Minimalist Operating System (MOS) ALPHA bootloader", 0
text2: db "Jumping into hyperspace (PMode in fact ...)", 0
text3: db "GDT and PMode enabled !", 0

gdt_start:
gdt_null: 
dd 0x0 
dd 0x0
gdt_code: ; the code segment descriptor
; base=0x0 , limit=0xfffff ,
; 1st flags : ( present )1 ( privilege )00 ( descriptor type )1 -> 1001 b
; type flags : ( code )1 ( conforming )0 ( readable )1 ( accessed )0 -> 1010 b
; 2nd flags : ( granularity )1 (32 - bit default )1 (64 - bit seg )0 ( AVL )0 -> 1100 b
dw 0xffff ; Limit ( bits 0 -15)
dw 0x0 ; Base ( bits 0 -15)
db 0x0 ; Base ( bits 16 -23)
db 10011010b ; 1st flags , type flags
db 11001111b ; 2nd flags , Limit ( bits 16 -19)
db 0x0 ; Base ( bits 24 -31)
gdt_data: ; the data segment descriptor
; Same as code segment except for the type flags :
; type flags: ( code )0 ( expand down )0 ( writable )1 ( accessed )0 -> 0010 b
dw 0xffff ; Limit ( bits 0 -15)
dw 0x0 ; Base ( bits 0 -15)
db 0x0 ; Base ( bits 16 -23)
db 10010010b ; 1st flags , type flags
db 11001111b ; 2nd flags , Limit ( bits 16 -19)
db 0x0 ; Base ( bits 24 -31)
gdt_end: ; The reason for putting a label at the end of the
gdt_descriptor :
dw gdt_end - gdt_start - 1 ; Size of our GDT , always less one
dd gdt_start ; Start address of our GDT
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

setupGDT:
cli ; Clear ints.
lgdt [gdt_descriptor]
mov eax, cr0 ; To make the switch to protected mode , we set
or eax, 0x1 ; the first bit of CR0 , a control register
mov cr0, eax ; Update the control register
ret