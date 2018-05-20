%define SYSCALL(n)			0x2000000 | n
%define READ				3
%define WRITE				4
%define BUFF_SIZE			0x100

section .text
	global _ft_cat

section .data
	buf: times BUFF_SIZE db 0

_ft_cat:
	push rbp						; setup stack frame
	mov rbp, rsp

	cmp edi, -1
	je end
	cmp edi, 255
	jg end

read_loop:
	push rdi
	lea rsi, [rel buf]
	mov rdx, BUFF_SIZE

	mov rax, SYSCALL(READ)			; call read, equivalent to {0x2000003}
	syscall

	test	rax, rax				; check for end
	jz		end_loop

	mov rdi, 1
	lea rsi, [rel buf]
	mov rdx, rax

	mov rax, SYSCALL(WRITE)			; call write, equivalent to {0x2000004}
	syscall

	jc end_loop			; check for error
	pop rdi
	jmp read_loop

end_loop:
	pop rdi

end:
	leave	; equivalent to {mov rsp, rbp} & {pop rbp},	restore stack frame
	ret
