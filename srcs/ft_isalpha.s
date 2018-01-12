global ft_isalpha

extern table_type

section .text

ft_isalpha:			; int ft_isalpha
	lea     rax, [rel table_type]
	mov     al, byte[rax + rdi]
	and     al, 0b00000001
	movzx   eax, al
	ret
