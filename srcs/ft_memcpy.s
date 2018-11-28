; http://faydoc.tripod.com/cpu/movsb.htm
; http://blog.rewolf.pl/blog/?p=177
; https://stackoverflow.com/questions/43343231/enhanced-rep-movsb-for-memcpy

global		_ft_memcpy

section .text

ALIGN 16
_ft_memcpy:         ; void   *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
    push rbp
	mov rbp, rsp

	mov rax, rdi   ; src (rdi) contains what should be put in dst
	mov rcx, rdx   ; how many times we repeat: rcx = n (rdx)
	rep movsb

	leave
	ret
