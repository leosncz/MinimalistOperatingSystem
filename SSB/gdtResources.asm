; GDT things of MOS Operating System.
; Check the license at GitHub.com/leosncz/OperatingSystem/
; NASM syntax.
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
gdt_end:
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
