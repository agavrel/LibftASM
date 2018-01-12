global	ft_strdup
extern	ft_memcpy
extern	ft_strlen
extern	_malloc

section .text

ft_strdup:
	push    rbp
	mov     rbp, rsp
    push    rdi
    call    ft_strlen
    inc     rax
    push    rax
    mov     rdi, rax
    call    _malloc
    test    rax, rax
    jz      .end
    mov     rdi, rax
    pop     rdx
    pop     rsi
    call    ft_memcpy

.end:
	mov     rsp, rbp
	pop     rbp
    ret
