global _ft_strncmp

section .text

_ft_strncmp:	; int	ft_strncmp(const char *s1, const char *s2, size_t n)
	push	rbp
	mov		rbp, rsp

	xor		eax, eax   	; return value = 0

	test	rcx, rcx	; protection: checks that n is different from 0
	jz      .end

.while:	; keep looping while both are equal
	cmp		byte edi, esi
	jne		.different	; check that both are equal

	inc		eax ; debug line ro removed

	inc		rdi			; increment *s1
	inc		rsi			; increment *s2
	dec		rcx			; decrement n
	jnz		.while		; if (n != 0) keep looping

.end:
	leave
	ret

.different:
;	mov		al, [rdi]
;	sub		al, [rsi]
;	movsx	rax, al
;	shr		rax, 31
;	xor		rax, 0xffffffff

	leave
	ret
