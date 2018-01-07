global _ft_isdigit

extern table_type

section .text

_ft_isdigit:
	lea     rax, [rel table_type]
	mov     al, byte[rax + rdi]
	and     al, 0b00000010
	movzx   eax, al
	ret
