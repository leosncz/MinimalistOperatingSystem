; Execute kmain function.
; Nasm syntax.
[bits 32]
[extern _kmain]
[global _main]
_main:
call _kmain
; When kernel's return point is reached (It shouldn't !)
jmp $ ; Loop 
