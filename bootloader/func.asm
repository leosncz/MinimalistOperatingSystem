printInt: ; Print the SI register to the screen.
push ax ; Save ax so it is preserved.
printInt2:
mov ah, 0x0E
mov al, [si]
cmp al, 0
je finPrintInt
int 0x10
inc si
jmp printInt2
finPrintInt:
pop ax
ret
