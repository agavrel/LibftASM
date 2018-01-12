; http://6.035.scripts.mit.edu/sp16/x86-64-architecture-guide.html

global ft_memset

section .text

ft_memset:
	cmp	rdi, 0
	je	.error		; jump to label .error if rdi is equal to 0

	mov r10, rdi	; saves rdi in r10
	mov al, sil
	mov rcx, rdx

	cld				; clear direction flag
	rep stosb

	mov rax, r10	; saves r10 in rax;
	ret

.error:
	mov rax, rdi
	ret
