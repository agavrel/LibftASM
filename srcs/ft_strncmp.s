global _ft_strncmp

section .text

_ft_strncmp:	; int	ft_strncmp(const char *s1, const char *s2, size_t n)
	push	rbp
	mov		rbp, rsp

	xor		eax, eax  	 	; return value = 0

	test	rdx, rdx		; protection: checks that n is different from 0
	jz      .end

.while:	; keep looping while both are equal
	mov		cl, BYTE[rdi]
	cmp		cl, BYTE[rsi]
	jne		.different		; check that both are equal : if (*s1 != *s2)

	inc		rdi				; increment *s1
	inc		rsi				; increment *s2
	dec		rdx				; decrement n
	jnz		.while			; if (n != 0) keep looping

.end:
	leave
	ret

.different:
	sub		cl, BYTE[rsi]	; substract both values
	shr		ecx, 7			; get most significant bit (if rdi < rsi then ecx = 1 else 0)
	shl		ecx, 1			; multiply by 2, ecx becomes 2 or 0
	mov		eax, 1			; set eax at 1 (return value if rdi > rsi)
	sub		eax, ecx		; substract the content of ecx register

	leave
	ret
