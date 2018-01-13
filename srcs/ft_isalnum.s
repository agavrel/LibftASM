global _ft_isalnum

extern table_type

section .text

_ft_isalnum:			; int ft_isalnum
    lea     rax, [rel table_type]
    mov     al, byte[rax + rdi]
    and     al, 0b00000011
	setne	al
    movzx   eax, al
    ret
