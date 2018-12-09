; http://tuttlem.github.io/2013/01/08/strlen-implementation-in-nasm.html

global _ft_strlen

section .text

ALIGN 16			; memory alignment might help to speed-up
_ft_strlen:
	push  rcx                 ; we will trash in here

	xor   al, al              ; the byte that the scan will
						  ; compare to is zero

	mov   rcx, -1     ; underfow will set the maximum number of bytes

;	cld				; CLD (STD) clears (sets) the Direction flag, data goes onwards (backwards).
	repne scasb               ; while [rdi] != al, keep scanning
	; The REPNZ prefix (which is more readable in the REPNE form) repeats the scas as long as the comparison is false (REPeat while Not Equal) and ECX > 0. It also decrements ECX automatically in every iteration. ECX has been initialized to the longest possible string so that it doesn't terminate the loop early.

	not rcx			; Since ECX counts down from 0xffffffff (also known as -1), the resulting length will be -1-ECX
	sub rcx, 1		; len--

	mov rax, rcx	; ret = len

	pop   rcx                 ; restore the saved registers
	ret                       ; all done!
