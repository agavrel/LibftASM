global	_ft_strdup
extern	_ft_memcpy
extern	_ft_strlen
extern	_malloc

_ft_strdup:			; char *strdup(const char *s);
	push	rbp		; load stack, also use enter 0,0 instead
	mov		rbp, rsp

	cmp		rdi, 0
	je		.error	; if string is empty returns 0

	push	rdi		; saves rdi which is the src (const chr *s)
	call _ft_strlen	; when calling a function the returns address is pushed onto the stack
	inc		rax		; add the '\0' to the len
	push	rax		; saves len
	mov		rdi, rax	; stores len into rdi registry
	call	_malloc		; malloc

	test	rax, rax	; return null if malloc failed
	jz		.error

	mov		rdi, rax	; saves malloc returns value in rdi
	pop		rdx
	pop		rsi
	call	_ft_memcpy
	mov		rsp, rbp
	pop		rbp
	;leave
	ret

.error:
	xor		rax, rax	; sets return value to 0
	mov		rsp, rbp	; clean up stack	, can also use leave instead
	pop		rbp
	ret
