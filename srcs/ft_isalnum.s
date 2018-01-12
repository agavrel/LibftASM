global ft_isalnum

extern table_type

section .text

ft_isalnum:			; int ft_isalnum
    lea     rax, [rel table_type]
    mov     al, byte[rax + rdi]
    and     al, 0b00000100
	setne	al
    movzx   eax, al
    ret
