global _ft_isascii

section .text

; rdi : general register, destination address for mov and cmp

_ft_isascii:
	cmp rdi, 0		; cmp rdi with 0
	jl false		; jump to label if inferior
	cmp rdi, 127	; cmp rdi with 127
	jg false		; jump to label if greater
	mov eax, 1
	ret
false:
	mov eax, 0
	ret
