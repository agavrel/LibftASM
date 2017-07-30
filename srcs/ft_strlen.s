; http://tuttlem.github.io/2013/01/08/strlen-implementation-in-nasm.html

global _ft_strlen

section .text

_ft_strlen:		; int ft_strlen

	push	rbx                 ; save any registers that
	push	rcx                	; we will trash in here

	mov		rbx, rdi            ; rbx = rdi

	xor		al, al             	; the byte that the scan will
                            	; compare to is zero

	mov		rcx, 0xffffffff		; the maximum number of bytes
                            	; i'm assuming any string will
                            	; have is 4gb

	repne	scasb               ; while [rdi] != al, keep scanning

	sub		rdi, rbx            ; length = dist2 - dist1
	sub		rdi, 1				; removes the '\0'
	mov		rax, rdi            ; rax now holds our length

	pop		rcx                 ; restore the saved registers
	pop		rbx

	ret                       	; all done!
