global _ft_swap

section .text

_ft_swap:			    ; int ft_swap(int *a, int *b) : swaps two integers' value
    test   ecx, edx     ; checks if eax (a) is equal to ebx (b)
    je     .end         ; if so then we should avoid xoring a and b
	xor    ecx, edx     ; *a = *a + *b
    xor    edx, ecx     ; *b = *a - *b
    xor    ecx, edx     ; *a = *a - *b

.end
	ret
