global	_ft_strcat

section	.text

_ft_strcat:				; char *strcat(char *restrict s1, const char *restrict s2);
; protection against null strings
	test	rdi, rdi	; checks that rdi (s1) is different from NULL
	jz		.end
	test	rdi, rdi	; checks that rsi (s2) is different from NULL
	jz		.end

	mov r11, rdi	; save pointer to s1
	cld				; direction flag -> inc
	xor al, al		; xor al,al is a quick way to zero out a register.
					; It's a one-byte opcode in x86 assembler, v.s. 2bytes for mov al, 0.
					; scan value = '\0'

; declare iterator
	xor rcx, rcx	; int i = 0
; go to s1's end
	not rcx			; max iterator
	repne scasb		; scan s1 to '\0'
	dec rdi			; i-- (scan goes past '\0')
	mov r10, rdi	; save s1(end)

; reset iterator
	xor rcx, rcx	; i = 0
; get s2(len)
	mov rdi, rsi
	not rcx
	repne scasb
	not rcx			; iterator now equal to s2(len) + 1

; copy s2 to s1
	mov rdi, r10
	rep movsb

	mov rax, r11
	ret

.end:
	mov rax, rdi	; The strcat() functions return the pointer s1.
	ret
