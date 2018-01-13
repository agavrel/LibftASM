; not yet tested...

global _ft_bzero

section .text

_ft_bzero:
	call _ft_memset
	cmp	rdi, 0
	je	.error		; jump to label .error if rdi is equal to 0
	ret

.error:
	mov rax, rdi
	ret
