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
    movsx r8, r8b
    movsx r9, r9b
    sub r8, r9

    mov rax, r8
    pop r9
    pop r8
    ret

