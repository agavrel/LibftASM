; https://www.recurse.com/blog/7-understanding-c-by-learning-assembly
; http://www.lacl.fr/tan/asm

section .data
	msg db	"hello, world!"

global _main

extern _puts

section .text

_main:
	push rbp		; push a value to the stack
		; %rbp and %rsp are special purpose registers.
		; %rbp is the base pointer, which points to the base of the current stack frame,
		; and %rsp is the stack pointer, which points to the top of the current stack frame.
		; %rbp always has a higher value than %rsp because the stack starts
		; at a high memory address and grows downwards.

	mov rdi, msg
		; rdi : general register, destination address for mov and cmp

	call _puts		; call puts function

	pop rbp
		; restore registers to initial state

	mov rax, 0		; move 0 to rax
		; also works with "xor rax,rax" as it sets rax to 0
		; rax: general register, accumulator, contains functions' return value
	ret				; return (0);
