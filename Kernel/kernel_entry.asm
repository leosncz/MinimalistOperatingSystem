; Execute kmain function.
; Nasm syntax.
[bits 32]
[extern _kmain]
[global _main]
_main:
jmp _kmain ; At this point, I prefer jmp instead of call.
