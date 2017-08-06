;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ABOUT LEA ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; https://stackoverflow.com/questions/13064809/the-point-of-test-eax-eax
; Despite all the explanations, LEA is an arithmetic operation:
; LEA Rt, [Rs1+a*Rs2+b] => Rt = Rs1 + a*Rs2 + b
; It's just that its name is extremelly stupid for a shift+add operation.
; The reason for that was already explained in the top rated answers
; (i.e. it was designed to directly map high level memory references).



global _ft_strdup
extern _ft_strlen
extern _malloc
extern _ft_memcpy

section .text

_ft_strdup:        ; char *strdup(const char *s);

; The strdup() function returns a pointer to a new string which is a
; duplicate of the string s.  Memory for the new string is obtained
; with malloc(3), and can be freed with free(3).
; It returns NULL if insufficient memory was available, with
; errno set to indicate the cause of the error.

	push	rbp		; load stack
	mov		rbp, rsp

	cmp		rdi, 0
	je		.error	; error if returns 0

	push	rdi		; saves rdi which is the src (const chr *s)
	call _ft_strlen	; when calling a function the returns address is pushed onto the stack
	inc		rax		; add the '\0' to the len
	push	rax		; saves len
	mov	rdi, rax	; stores len into rdi registry

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ABOUT TEST ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; https://stackoverflow.com/questions/13064809/the-point-of-test-eax-eax
; TEST instruction performs a bitwise logical AND, discards the actual result
; and sets/unsets the ZF according to the result of the logical and: if the
; result is zero it sets ZF = 1, otherwise it sets ZF = 0.
	call	_malloc			; malloc
	test	rax, rax		; return null if malloc failed
	jz		.error

	mov		rdi, rax		; saves malloc returns value in rdi
	pop		rsi
	call _ft_memcpy			; copy from src (rdi) to rax;

.end:
	mov		rsp, rbp	; clean up stack
	pop		rbp
	ret

.error:
	xor		rax, rax	; sets return value to 0
	mov		rsp, rbp	; clean up stack
	pop		rbp
	ret
