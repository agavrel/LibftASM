global _ft_islower

extern _ft_isalpha

section .text

_ft_islower:			; int ft_islower
	call	_ft_isalpha
	test	eax, eax
	jz		.end
	and		edi, 0x20	; checks if 6th bit if ON
	jz		.end		; if not set, jumps to .end
	mov		eax, 1
	ret

 .end:
 	mov		eax, 0
	ret
