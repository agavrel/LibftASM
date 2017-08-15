; http://faydoc.tripod.com/cpu/movsb.htm
; http://blog.rewolf.pl/blog/?p=177
; https://stackoverflow.com/questions/43343231/enhanced-rep-movsb-for-memcpy

global		_ft_memcpy

_ft_memcpy:
	enter		0, 0
	push		rdi
	mov			rcx, rdx	;get len
	cld
	rep	movsb
	pop			rax
	leave
	ret
