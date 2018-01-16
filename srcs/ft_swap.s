global _ft_swap

section .text

_ft_swap:			    ; void ft_swap(int *a, int *b);
    mov    eax, [rdi]   ; tmp = *a;
    xchg   [rsi], eax   ;
    mov    [rdi], eax   ; *b = tmp;
    ret
