global _ft_isdigit

section .text

; rdi : general register, destination address for mov and cmp

_ft_isdigit:		; int ft_isdigit
	cmp rdi, 48		; cmp rdi with 48 ('0')
	jl false		; jump to label false if inferior
		; hence: if < '0' return 0

	cmp rdi, 57		; cmp rdi with 57 ('9')
	jg false		; jump to label false if greater
		; hence: if > '9' return 0

	mov eax, 1
	ret				; return 1

false:
	mov eax, 0
	ret				; return 0
