global _ft_tolower

extern _ft_isalpha

section .text

_ft_tolower:
	call	_ft_isalpha
	test	eax, eax
	jz		.end
	or		edi, 0x20	;	 0x20 : it clears the 6th bit if char is alpha.

 .end:
 	mov		eax, edi
	ret
