global _ft_rand

section .text

_ft_rand:      ; int ft_rand(void) : returns integer between 0 and 99
    rdrand  eax
    mov     ecx, 100
    mov     edx, 0
    div     ecx
    mov     eax, edx
    ret
