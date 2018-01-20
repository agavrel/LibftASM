global _ft_isalnum

extern table_type

section .text

_ft_isalnum:                            ; int ft_isalnum(int c);
    lea     rax, [rel table_type]       ; Load Effective (memory) Address of table_type in rax
    mov     eax, [rax + rdi]         ; rdi is int c, al contains 8 lowest bytes of rax, al = byte[&table_type + c]
    and     eax, 0b00000011              ; use mask to check if it is an alpha or digit as defined in table_type
    ret
