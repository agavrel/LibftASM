global _ft_islower

section .text

; rdi : general register, destination address for mov and cmp

_ft_islower:		; int ft_islower
	cmp rdi, 97		; cmp rdi with 97
	jl false		; jump to label false if inferior
		; hence: if < 0 return 0

	cmp rdi, 122	; cmp rdi with 122
	jg false		; jump to label false if greater
		; hence: if > 127 return 0

	mov eax, 1
	ret				; return 1

false:
	mov eax, 0
	ret				; return 0
