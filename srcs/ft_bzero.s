; not yet tested...

global ft_bzero

section .text

ft_bzero:
	call ft_memset
	cmp	rdi, 0
	je	.error		; jump to label .error if rdi is equal to 0
	ret

.error:
	mov rax, rdi
	ret
