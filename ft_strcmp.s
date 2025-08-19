section .text
global ft_strcmp

; rdi = s1
; rsi = s2
ft_strcmp:
    xor rax, rax
    push r8
    push r9

.loop:
    mov r8b, byte [rdi + rax]
    mov r9b, byte [rsi + rax]
    cmp r8b, r9b
    jne .end
    cmp r8b, 0
    je .end
    inc rax
    jmp .loop

.end:
    sub r8b, r9b
    movsx rax, r8b
    pop r9
    pop r8
    ret

