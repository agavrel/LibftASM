global ft_tolower

extern ft_isalpha

section .text

ft_tolower:
	call	ft_isalpha
	test	eax, eax
	jz		.end
	or		edi, 0x20	;	 0x20 : it clears the 6th bit if char is alpha.

 .end:
 	mov		eax, edi
	ret
