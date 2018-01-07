global _ft_isupper

extern _ft_isalpha

section .text

_ft_isupper:			; int ft_isupper
	call	_ft_isalpha
	test	eax, eax
	jz		.end
	and		edi, 0x20	; checks if 6th bit if ON
	jnz		.end		; if set, jumps to .end
	mov		eax, 1
	ret

.end:
	mov		eax, 0
	ret
