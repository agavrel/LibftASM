; https://en.wikipedia.org/wiki/X86_calling_conventions

global _ft_isalnum

extern _ft_isalpha
extern _ft_isdigit

section .text

_ft_isalnum:			; int ft_isalnum

.enter:
	push rbp
	mov rbp, rsp		; move stack pointer to base pointer

	call _ft_isdigit	; call lower function
	cmp rax, 1			; checks if it returns 1
	je .true			; if equal jump to

	call _ft_isalpha
	cmp rax, 1
	je .true

	mov rax, 0			; returns 0 if not isdigit or isalpha

.leave:
	mov rsp, rbp
	pop rbp
	ret					; return value on rax

.true:
	mov rax, 1
	jmp .leave
