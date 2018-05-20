global _ft_atoi

section .text

_ft_atoi:					; int ft_atoi(const char *str);
	push	rbp				; setup stack frame
	mov		rbp, rsp

	mov		rax, 0			; default return value
	mov		rdx, 1			; sign

.while_sp:
	mov		dl, BYTE[rdi]
	inc		rdi				; go to next char
	cmp		dl, 32			; skip spaces
	je		.while_sp
	sub 	dl, 9			; test characters 9 to 13
	cmp 	dl, (13 - 9)
	jle		.while_sp

	mov		dl, BYTE[rdi]
	cmp		dl, 0x2b		; +
;	sete	edx, 1			; useless in fact
	cmp		dl, 0x2d		; -
;	cmove	edx, -1			; set sign to negative

.while_num:
	mov		dl, BYTE[rdi]

	cmp		dl, 0x30		; test for \0 and any value beloz '0'
	jl		.end

	sub 	dl, 0x30		; substract '0' to character
	cmp 	dl, (9 - 0)
	ja		.end			; checks that its a digit and not a character above

	imul	rax, 10			; multiply previous value by 10
	add		rax, rdx		; add the value of the current letter
	inc		rdi				; go to next char
	jmp		.while_num		; keep looping

.end:
	leave					; clear stack frame
	ret
