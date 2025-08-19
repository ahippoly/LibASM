extern ft_set_errno

section .text
  global ft_read

; ssize_t ft_read(int fd, void *buf, size_t count);
; Implementation of read system call
; Input: rdi = file descriptor, rsi = buffer pointer, rdx = count
; Output: rax = number of bytes read, or -1 on error

ft_read:
    ; Set up system call arguments
    ; rdi already contains fd (first argument) rdi = fd
    ; rsi already contains buf (second argument) rsi = buf
    ; rdx already contains count (third argument) rdx = count
    mov     rax, 0          ; sys_read system call number
    syscall
    
    ; Check for error (negative return value)
    cmp     rax, 0
    jl      .error_occurred
    
    ret

.error_occurred:
    ; On error, syscall returns a negative error code
    ; We need to negate it and store it in errno, then return -1
    call    ft_set_errno
    mov     rax, -1         ; Return -1
    ret

