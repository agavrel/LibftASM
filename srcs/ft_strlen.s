; http://tuttlem.github.io/2013/01/08/strlen-implementation-in-nasm.html

global _ft_strlen

section .text

ALIGN 16			; memory alignment might help to speed-up
_ft_strlen:
	push rbp
	mov rbp, rsp

	xor	rax, rax
	mov rcx, -1
;	xor rcx, rcx	; int len = 0;
;	not rcx			; invert all bytes without affecting flags

	cld				; CLD (STD) clears (sets) the Direction flag, data goes onwards (backwards).
	repnz scasb		; The REPNZ prefix (which is more readable in the REPNE form) repeats the scas as long as the comparison is false (REPeat while Not Equal) and ECX > 0. It also decrements ECX automatically in every iteration. ECX has been initialized to the longest possible string so that it doesn't terminate the loop early.

	not rcx			; Since ECX counts down from 0xffffffff (also known as -1), the resulting length will be -1-ECX
	sub rcx, 1		; len--

	mov rax, rcx	; ret = len

	leave
	ret
