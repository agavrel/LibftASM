global ft_swap

section .text

ft_swap:			    ; int ft_swap(int *a, int *b);
    mov    eax, [rdi]   ; tmp = *a;
	xor    eax, [rsi]    ; *a = *a + *b
    xor    [rsi], eax    ; *b = *a - *b
    xor    eax, [rsi]    ; *a = *a - *b
    mov    [rdi], eax   ; *a = tmp;
    ret
