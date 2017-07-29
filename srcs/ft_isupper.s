global _ft_isupper

section .text

; rdi : general register, destination address for mov and cmp

_ft_isupper:		; int ft_isupper
	cmp rdi, 65		; cmp rdi with 65
	jl false		; jump to label false if inferior
		; hence: if < 65 return 0

	cmp rdi, 90		; cmp rdi with 90
	jg false		; jump to label false if greater
		; hence: if > 90 return 0

	mov eax, 1
	ret				; return 1

false:
	mov eax, 0
	ret				; return 0
