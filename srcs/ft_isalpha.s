global _ft_isalpha

section .text

; rdi : general register, destination address for mov and cmp

_ft_isalpha:		; int ft_isalpha
	push rbp
	mov rbp, rsp
	sub rsp, 8
	mov eax, edi
	mov BYTE PTR [rbp-4], al
	movsx eax, BYTE PTR [rbp-4]
	mov edi, eax
	call ft_islower(char)
	test eax, eax
	je .L6
	movsx eax, BYTE PTR [rbp-4]
	mov edi, eax
	call ft_isupper(char)
	test eax, eax
	jne .L7
.L6:
	mov eax, 1
	jmp .L8
.L7:
	mov eax, 0
.L8:
	test al, al
	je .L9
	mov eax, 0
	 jmp .L10
.L9:
	 mov eax, 1
.L10:
	 leave
	 ret
