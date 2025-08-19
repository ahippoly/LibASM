section .text
global _start

_start:
    mov rax, 60        ; sys_exit system call number
    mov rdi, 0         ; exit status (0 = success)
    syscall            ; invoke system call

