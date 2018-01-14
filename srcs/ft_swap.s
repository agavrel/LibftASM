global ft_swap

section .text

ft_swap:			    ; int ft_swap(int *a, int *b);
    mov    eax, [rdi]   ; tmp = *a;
    xchg   [rsi], eax   ;
    mov    [rdi], eax   ; *b = tmp;
    ret
