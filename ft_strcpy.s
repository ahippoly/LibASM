section .text
global ft_strcpy

; rdi = dest
; rsi = src
ft_strcpy:
    xor rax, rax
    push r12

.loop:
    mov r12b, byte [rsi + rax]
    mov byte [rdi + rax], r12b
    cmp r12b, 0
    je .end
    inc rax
    jmp .loop

.end:
    pop r12
    mov rax, rdi
    ret

