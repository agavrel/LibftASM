; http://faydoc.tripod.com/cpu/movsb.htm
; http://blog.rewolf.pl/blog/?p=177
; https://stackoverflow.com/questions/43343231/enhanced-rep-movsb-for-memcpy

global _ft_memcpy

section .text

_ft_memcpy:
	; void *memcpy(void *restrict dst, const void *restrict src, size_t n);

; The locations of the source and destination operands are always specified by
; the DS:(E)SI and ES:(E)DI registers, which must be loaded correctly
; before the move string instruction is executed.

	cmp	rdi, 0			; src
	je	.error

	cmp	rsi, 0			; dst
	je	.error

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	rep movsb			; Moves the byte, word, or doubleword specified with
						; the second operand (source operand) to the location
						; specified with the first operand (destination operand)

.error:
	ret
