[bits 32]
[extern _kmain]
[global _main]
_main:
call _kmain
jmp $