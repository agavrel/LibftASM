global	_ft_strdup
extern	_ft_memcpy
extern	_ft_strlen
extern	_malloc

section .text

_ft_strdup:
	push    rbp
	mov     rbp, rsp
    push    rdi
    call    _ft_strlen
    inc     rax
    push    rax
    mov     rdi, rax
    call    _malloc
    test    rax, rax
    jz      .end
    mov     rdi, rax
    pop     rdx
    pop     rsi
    call    _ft_memcpy

.end:
	mov     rsp, rbp
	pop     rbp
    ret
