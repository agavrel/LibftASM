global _ft_isupper

extern table_type

section .text

_ft_isupper:							; int ft_isupper(int c);
	lea     rax, [rel table_type]		; Load Effective (memory) Address of table_type in rax
	test    byte[rax + rdi], 0b00000001	; use mask to check if it is an alpha as defined in byte[&table_type + c]					; set 'eax' (which is the returned 4 bytes value) equal to al and feels the remaining bits with 0.
	setnz	al							; set al to 1 if alpha
	and		edi, 0x20					; checks if 6th bit is set. If the bit is set it will set the ZF
	setz	cl							; set cl to 1 if set
	and		al, cl						; if either condition was false will store 0 instead of 1 in al
	movzx	eax, al						; will return al
	ret
