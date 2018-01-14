global _ft_swap

section .text

_ft_swap:			    ; int ft_swap(int *a, int *b) : swaps two integers' value
    test   eax, ebx     ; checks if eax (a) is equal to ebx (b)
    je     .end         ; if so then we should avoid xoring a and b
	xor    eax, ebx     ; *a = *a + *b
    xor    ebx, eax     ; *b = *a - *b
    xor    eax, ebx     ; *a = *a - *b

.end
	ret
