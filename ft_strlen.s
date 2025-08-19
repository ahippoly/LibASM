section .text
global ft_strlen

; size_t ft_strlen(const char *s);
; Implementation of strlen function from libc
; Input: rdi = pointer to null-terminated string
; Output: rax = length of string (number of characters before null terminator)

ft_strlen:
    ; Initialize counter to 0
    xor rax, rax                ; rax = 0 (length counter)
    
.loop:
    ; Load byte from string and check if it's null terminator
    cmp byte [rdi + rax], 0     ; compare byte at [rdi + rax] with 0
    je .done                    ; if zero (null terminator), we're done
    
    ; Increment counter and continue
    inc rax                     ; increment length counter
    jmp .loop                   ; continue loop
    
.done:
    ret                         ; return length in rax
