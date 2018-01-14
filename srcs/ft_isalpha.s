global _ft_isalpha

extern table_type

section .text

_ft_isalpha:							; int ft_isalpha(int c)
	lea     rax, [rel table_type]		; Load Effective (memory) Address of table_type in rax
	mov     al, byte[rax + rdi]			; rdi is int c, al contains 8 lowest bytes of rax, al = byte[&table_type + c]
	and     al, 0b00000001				; use mask to check if it is an alpha as defined in table_type
	movzx   eax, al						; set 'eax' (which is the returned 4 bytes value) equal to al and feels the remaining bits with 0.
	ret
