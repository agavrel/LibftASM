global _ft_abs

section .text

_ft_abs:			; int ft_abs(int x)
    mov eax, edi    ; return value = x
    cdq             ; Copy sign bit of eax to all bits of edx
    add eax, edx    ; Add 1 if negative
    xor eax, edx    ; Invert all bits if negative
	ret
