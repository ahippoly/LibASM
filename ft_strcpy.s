section .text
global ft_strcpy

; rdi = dest
; rsi = src
ft_strcpy:
    xor rax, rax

.loop:
    mov r8b, byte [rsi + rax]
    mov byte [rdi + rax], r8b
    cmp r8b, 0
    je .end
    inc rax
    jmp .loop

.end:
    mov rax, rdi
    ret

