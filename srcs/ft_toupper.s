global _ft_toupper

extern table_type					; includes table_type

section .text

_ft_toupper:													; int	ft_toupper(int c);
	lea     rcx, [rel table_type]				; Load Effective (memory) Address of table_type in rax
	mov		eax, edi
	and		eax, 0xffffffdf								; it clears the 6th bit which is the diff between lower and uppercase letters
	test    byte[rcx + rdi], 0b00000001 ; rdi is int c, al contains 8 lowest bytes of rax, al = byte[&table_type + c]
	cmovz	eax, edi											; set function's return value 'eax' equals to edi, which is int c passed, if it was an alpha
	ret
