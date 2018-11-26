global _ft_align				; align given size on 2^n, mask should be equal to 2^n - 1

section .text

_ft_align:					; unsigned long ft_align(unsigned long size, unsigned long mask);
  lea     rax, [rdi+rsi]  ; return (rax) = size (rdi) + mask (rsi)
  not     rsi             ; mask = ~mask
  and     rax, rsi        ; (rax) &= (rsi)
  ret
