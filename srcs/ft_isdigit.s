global _ft_isdigit

; extern table_type

section .text

_ft_isdigit:
	sub			edi, '0'	; substract 48 ('0') to edi
	cmp			dil, 9		; compare edi with 9
	setbe		al				; if below or equal 9 then it was a digit
	ret

; _ft_isdigit:
;	lea     rax, [rel table_type]
;	mov     al, byte[rax + rdi]
;	and     al, 0b00000010
;	movzx   eax, al
;	ret
