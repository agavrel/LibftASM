global _ft_toupper

section .text

_ft_toupper:
	cmp rdi, 'a'
	jl .end

	cmp rdi, 'z'
	jg .end

	sub rdi, 32

.end:
	mov rax, rdi
	ret
