; https://en.wikipedia.org/wiki/ASCII#ASCII_printable_characters

global _ft_isprint

extern table_type

section .text

_ft_isprint:
    lea     rax, [rel table_type]
    mov     al, byte[rax + rdi]
    and     al, 0b00001000
    movzx   eax, al
    ret
