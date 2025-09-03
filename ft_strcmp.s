section .text
global ft_strcmp

; rdi = s1
; rsi = s2
ft_strcmp:
    xor rax, rax
    push r12
    push r13

.loop:
    mov r12b, byte [rdi + rax]
    mov r13b, byte [rsi + rax]
    cmp r12b, r13b
    jne .end
    cmp r12b, 0
    je .end
    inc rax
    jmp .loop

.end:
    movsx r12, r12b
    movsx r13, r13b
    sub r12, r13

    mov rax, r12
    pop r13
    pop r12
    ret

