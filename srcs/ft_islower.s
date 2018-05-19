global _ft_islower

extern table_type

section .text

_ft_islower:							; int ft_islower(int c);
	lea     rax, [rel table_type]		; Load Effective (memory) Address of table_type in rax
	test    byte[rax + rdi], 0b00000001	; use mask to check if it is an alpha as defined in byte[&table_type + c]					; set 'eax' (which is the returned 4 bytes value) equal to al and feels the remaining bits with 0.
	setnz	al							; set al to 1 if alpha
	and		edi, 0x20					; checks if 6th bit is set. If the bit is not set it will set the ZF
	setnz	cl							; set cl to 1 if set
	and		al, cl						; if either condition was false will store 0 instead of 1 in al
	movzx	eax, al						; will return al
	ret
