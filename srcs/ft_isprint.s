; https://en.wikipedia.org/wiki/ASCII#ASCII_printable_characters

global _ft_isprint

section .text

_ft_isprint:		; int ft_isprint
	cmp rdi, 32		; cmp rdi with 32 (first printable char)
	jl false		; jump to label false if inferior
		; hence: if < '0' return 0

	cmp rdi, 126	; cmp rdi with 126 (last printable char)
	jg false		; jump to label false if greater
		; hence: if > '9' return 0

	mov eax, 1
	ret				; return 1

false:
	mov eax, 0
	ret				; return 0
