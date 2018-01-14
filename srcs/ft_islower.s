global _ft_islower

extern table_type

section .text

_ft_islower:							; int ft_isupper(int c);
	lea     rax, [rel table_type]		; Load Effective (memory) Address of table_type in rax
	mov     al, byte[rax + rdi]			; rdi is int c, al contains 8 lowest bytes of rax, al = byte[&table_type + c]
	and     al, 0b00000001				; use mask to check if it is an alpha as defined in table_type
	movzx   eax, al						; set 'eax' (which is the returned 4 bytes value) equal to al and feels the remaining bits with 0.
	and		edi, 0x20					; checks if 6th bit is set. If the bit is not set it will set the ZF
	jz		.end						; if ZF is set, jumps to .end to set return value to 0, else keep it as it was (1 if alpha, 0 otherwise).
	ret

 .end:
 	mov		eax, 0
	ret
