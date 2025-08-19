extern __errno_location

section .text
global ft_set_errno

ft_set_errno:
  push rdi
  mov     rdi, rax        ; Save the negative error code
  neg     rdi             ; Convert to positive error code
  
  ; Get errno location
  call    __errno_location wrt ..plt
  
  ; Store error code in errno
  mov     dword [rax], edi
  pop rdi
