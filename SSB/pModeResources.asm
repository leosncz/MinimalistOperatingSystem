; PMode resources of MOS Operating System.
; Check the license at GitHub.com/leosncz/OperatingSystem/
; NASM syntax.

writeCharacterToVideoMemoryFunc: ; al=character ah=attributes cx=offset(byte)
push si
mov esi, 0xB8000
add si, cx
mov byte [esi], al
mov byte [esi+1], ah
pop si
ret

writeSIToVideoMemory: ; cx=offset
mov al, [si]
cmp al, 0
je endWSITVM
mov ah, 00001111b
call writeCharacterToVideoMemoryFunc
inc si
add cx, 2d
jmp writeSIToVideoMemory
endWSITVM:
ret
