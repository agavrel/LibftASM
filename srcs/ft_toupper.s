global ft_toupper

extern ft_isalpha

section .text

ft_toupper:
	call	ft_isalpha
	test	eax, eax
	jz		.end
	and		edi, 0xffffffdf	;	0xffffffdf - 0x20 : it sets the 6th bit to 1

 .end:
 	mov		eax, edi
	ret
