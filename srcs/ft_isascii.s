global _ft_isascii

section .text

_ft_isascii:							; int ft_isascii
	and     edi, 0xffffff80 ; mask with the 128 firsts bits left to 0 as ASCII range from 0 to 7f in hexa (just below 80)
	sete    al 							; SETE sets AL to 1 if above condition code means "equal", otherwise it sets AL to 0.
 	movzx   eax, al					; set 'eax' (which is the returned 4 bytes value) equal to al and feels the remaining bits with 0.
	ret
