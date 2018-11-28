; http://6.035.scripts.mit.edu/sp16/x86-64-architecture-guide.html

global _ft_memset
global _ft_bzero

section .text

ALIGN 16
_ft_bzero:							; void	ft_bzero(void *s, size_t n);
	push rbp
	mov rbp, rsp

	mov rcx, rsi			; how many time should we repeat, rcx = n (rsi)
	xor al, al				; set al to 0

	rep stosb

	leave
	ret

_ft_memset:					; void	*ft_memset(void *s, int c, size_t n);
	push rbp
	mov rbp, rsp

	mov rcx, rdx			; how many time should we repeat, rcx = n (rdx)
	mov eax, esi  			; set the value to be copied = int c

	rep stosb

	leave
	ret
