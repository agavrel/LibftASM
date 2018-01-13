global _ft_isupper

extern _ft_isalpha

section .text

_ft_isupper:			; int ft_isupper
	call	_ft_isalpha
	cmovz	eax, eax	; {test eax, eax + mov eax 0}: if ft_isalpha returns 0 move 0 to eax
	and		edi, 0x20	; checks if 6th bit if ON
	cmovnz	eax, eax
	jnz		.end		; if not set, jumps to .end
	ret

.end:
	mov		eax, 0
	ret
