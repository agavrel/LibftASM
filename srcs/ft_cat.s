%define SYSCALL(n)		(0x2000000 | n)
%define READ					3
%define WRITE					4
%define BUFF_SIZE			0x100
%define STDOUT				1

section .text
	global _ft_cat

_ft_cat:
	push rbp								; setup stack frame
	mov rbp, rsp

	push rbx                ;	backup preserved register
	sub rsp, 8              ;	16bit align stack

	sub rsp, BUFF_SIZE      ;	make a big stack buffer

	mov rbx, rdi            ;	store fd in a preserved register

.loop:
	mov rdi, rbx            ;	fd
	mov rsi, rsp            ;	buffer
	mov rdx, BUFF_SIZE - 1  ;	read size
	mov rax, SYSCALL(READ)  ;	call read
	syscall

	jc .end                 ;	quit if carry flag was set (error)
	test rax, rax           ;	check for '\0'
	je .end


	mov rdi, STDOUT
	mov rsi, rsp            ;	buffer on stack
	mov rdx, rax            ;	length returned by read
	mov rax, SYSCALL(WRITE) ;	call write
	syscall

	jmp .loop

.end:
	add rsp, BUFF_SIZE    	;	destroy big stack buffer
	add rsp, 8
	pop rbx                 ;	restore rbx
	leave										; equivalent to {mov rsp, rbp} & {pop rbp},	restore stack frame
	ret
