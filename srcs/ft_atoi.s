global _ft_atoi				; similar to original atoi except it does not overflow, return 0 instead

section .text

_ft_atoi:					; int ft_atoi(const char *str);
	push	rbp				; setup stack frame
	mov		rbp, rsp

	xor		rax, rax		; default return value
	mov		rsi, 1			; sign
	xor		rcx, rcx		; used to handle sign later

.while_sp:
	mov		dl, BYTE[rdi]
	inc		rdi				; go to next char
	cmp		dl, 32			; skip spaces
	je		.while_sp
	sub 	dl, 9			; test characters 9 to 13
	cmp 	dl, (13 - 9)
	jle		.while_sp
	dec		rdi

.sign_handler:
	mov		dl, BYTE[rdi]

	cmp		dl, 0x2b		; 0x2b = '+'
	sete	cl				; used to increase pointer

	cmp		dl, 0x2d		; 0x2d = '-'
	cmove	rsi, rax		; set sign to negative
	sete	cl

	add		rdi, rcx		; increase pointer

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
	test	rsi, rsi		; test if sign is positive (1) or negative (0)
	jz		.negate

	leave					; clear stack frame
	ret

.negate:
	neg		eax;			; if negative reverse result
	leave					; clear stack frame
	ret
