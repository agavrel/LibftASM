global  ft_strcpy
extern  ft_strlen
extern	ft_memcpy

section .text

ft_strcpy:				;char *stpcpy(char * dst, const char * src);
	push	rdi			; dst
	push	rsi			; src
	mov		rdi, rsi	; dst = src
	call	ft_strlen
	mov		rbx, rax
	pop		rsi			; cleanup
	pop		rdi
	call	ft_memcpy
	ret
