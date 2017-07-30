global _ft_isascii

section .text

; rdi : general register, destination address for mov and cmp

_ft_isascii:		; int ft_isascii
	cmp rdi, 0		; cmp rdi with 0
	jl false		; jump to label false if inferior
		; hence: if < 0 return 0

	cmp rdi, 127	; cmp rdi with 127
	jg false		; jump to label false if greater
		; hence: if > 127 return 0

	mov rax, 1
	ret				; return 1

false:
	mov rax, 0
	ret				; return 0
