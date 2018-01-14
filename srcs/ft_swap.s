global _ft_swap

section .text

_ft_swap:			    ; int ft_swap(int *a, int *b) : swaps two integers' value
    test   edi, esi     ; checks if eax (a) is equal to ebx (b)
    je     .end         ; if so then we should avoid xoring a and b
	xor    edi, esi     ; *a = *a + *b
    xor    esi, edi     ; *b = *a - *b
    xor    edi, esi     ; *a = *a - *b

.end
	ret
