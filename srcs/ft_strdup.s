global	_ft_strdup
extern	_ft_memcpy
extern	_ft_strlen
extern	_malloc

section .text

_ft_strdup:				; char			*ft_strdup(const char *s);
	push    rbp
	mov     rbp, rsp

    push    rdi			; call strlen by sending rdi (char *s)
    call    _ft_strlen
    inc     rax			; add 1 to malloc size for '\0'
    push    rax
    mov     rdi, rax
    call    _malloc

    test    rax, rax	; malloc protection : if malloc failed returns NULL
    jz      .end

    mov     rdi, rax
    pop     rdx
    pop     rsi
    call    _ft_memcpy

.end:
	leave
    ret
