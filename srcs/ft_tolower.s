global _ft_tolower

section .text

_ft_tolower:							; int	ft_tolower(int c);
	lea     edx, [edi - ('A')]	; we substract the value of the letter A
	mov     eax, edi			; return value set to input value
	or      edi, 0x20			; create a lowercase version
	cmp     edx, 'Z'-'A'		; that we will use only if we were facing an upper case character
	cmovb   eax, edi			; if it was, we move value from edi to eax
	ret

