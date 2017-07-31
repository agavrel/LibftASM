; https://www.recurse.com/blog/7-understanding-c-by-learning-assembly
; http://www.lacl.fr/tan/asm

section .data
	msg db	"hello, world!"

global _ft_puts

extern _puts

section .text

_ft_puts:
	push	rbp			; push a value to the stack
	mov		rbp, rsp	;
	call	_puts		; call puts function
	mov		rax, 0		; move 0 to rax
	mov		rsp, rbp	;
	pop		rbp			; restore registers to initial state
	ret					; return (0);
