  extern ft_set_errno

section .text
  global ft_write
  
; ssize_t ft_write(int fd, const void *buf, size_t count);
; Implementation of write system call
; Input: rdi = file descriptor, rsi = buffer pointer, rdx = count
; Output: rax = number of bytes written, or -1 on error

ft_write:
    ; Set up system call arguments
    ; rdi already contains fd (first argument) rdi = fd
    ; rsi already contains buf (second argument) rsi = buf
    ; rdx already contains count (third argument) rdx = count
    mov     rax, 1          ; sys_write system call number
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
