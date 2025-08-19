extern  ft_strlen
extern  ft_strcpy
extern  malloc

section .text
    global  ft_strdup

; rdi = str
ft_strdup:
    push    rdi
    call    ft_strlen
    mov     rdi, rax
    add     rdi, 1
    call    malloc wrt ..plt
    cmp     rax, 0
    je      .error
    mov     rdi, rax
    pop     rsi ; rsi = str
    jmp     ft_strcpy

.error:
    pop     rax
    xor     rax, rax
    ret
