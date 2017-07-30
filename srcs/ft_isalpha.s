; https://en.wikipedia.org/wiki/X86_calling_conventions

global _ft_isalpha

extern _ft_islower
extern _ft_isupper

section .text

; rdi : general register, destination address for mov and cmp

_ft_isalpha:		; int ft_isalpha
.enter:
	push rbp
	mov rbp, rsp	; move stack pointer to base pointer
	
	call _ft_islower	; call lower function
	cmp rax, 1			; checks if it returns 1
	je .true			; if equal jump to

	call _ft_isupper
	cmp rax, 1
	je .true

	mov rax, 0

.leave:
	mov rsp, rbp
	pop rbp
	ret				; return value on rax

.true:
	mov rax, 1
	jmp .leave
