global  _ft_strcpy

extern  _ft_strlen
extern	_ft_memcpy

section .text

_ft_strcpy:				;char *stpcpy(char * dst, const char * src);
	push	rdi			; dst
	push	rsi			; src
	mov		rdi, rsi	; dst = src
	call	_ft_strlen
	mov		rbx, rax
	pop		rsi			; cleanup
	pop		rdi
	call	_ft_memcpy
	ret
