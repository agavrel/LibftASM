global _ft_tolower

extern table_type					; includes table_type

section .text

_ft_tolower:						; int	ft_tolower(int c);
	lea     rax, [rel table_type]	; Load Effective (memory) Address of table_type in rax
	mov     al, byte[rax + rdi]		; rdi is int c, al contains 8 lowest bytes of rax, al = byte[&table_type + c]
	and     al, 0b00000001			; use mask to check if it is an alpha as defined in table_type
	mov		eax, edi				; set function's return value 'eax' equals to edi, which is int c passed
	jz		.end					; if mask failed, zero flag is ON so just return, if not it will do below:
	or		eax, 0x20				; 0x20 : it clears the 6th bit which is the diff between lower and uppercase letters

 .end:
 	ret
