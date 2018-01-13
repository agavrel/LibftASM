; http://6.035.scripts.mit.edu/sp16/x86-64-architecture-guide.html

global _ft_memset
global _ft_bzero

section .text

_ft_bzero:							; void	ft_bzero(void *s, size_t n);
	mov         rdx, rsi			
	pxor        xmm8, xmm8
	jmp         _ft_memset.start


_ft_memset:						; void	*ft_memset(void *s, int c, size_t n);
    mov         rax, rdi
    movd        xmm8, esi
    punpcklbw   xmm8, xmm8              ; 0xAABBCCDDEEFFGGHHIIJJKKLLMMNNOOPP -> 0xAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH
    punpcklwd   xmm8, xmm8              ; 0xAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH -> 0xAAAAAAAABBBBBBBBCCCCCCCCDDDDDDDD
    pshufd      xmm8, xmm8, 0x0         ; 0xAAAAAAAABBBBBBBBCCCCCCCCDDDDDDDD -> 0xAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

.start:
    cmp         rdx, 0x10
    jbe         .short			; jump to .short if rdx is below or equal to 0x10
    cmp         rdx, 0x40
    ja          .long			; jump to .long if rdx is above 0x40
    movdqu      [rdi], xmm8
    movdqu      [rdi + rdx - 0x10], xmm8
    cmp         rdx, 0x20
    jbe         .mediumend		; jump to .mediumend if rdx is below or equal to 0x20

.medium:						; hence will execute the following if (0x40 >= rdx > 0x20)
    movdqu      [rdi + 0x10], xmm8
    movdqu      [rdi + rdx - 0x20], xmm8

.mediumend:
    ret

.short:
    movq        rcx, xmm8
    test        dl, 0b11000
    jne         .shortlong
    test        dl, 0b00100
    jne         .shortmedium
    test        dl, 0b00001
    je          .veryshort
    mov         [rdi], cl

.veryshort:
    test        dl, 0b00010
    je          .shortend
    mov         [rdi + rdx - 0x2], cx

.shortend:
    ret

.shortshort:
    mov         [rdi], cx
    mov         [rdi + rdx - 0x2], cx
    ret

.shortmedium:
    mov         [rdi], ecx
    mov         [rdi + rdx - 0x4], ecx
    ret

.shortlong:
    mov         [rdi], rcx
    mov         [rdi + rdx - 0x8], rcx
    ret

.long:
    movdqu      [rdi], xmm8
    movdqu      [rdi + rdx - 0x10], xmm8
    movdqu      [rdi + 0x10], xmm8
    movdqu      [rdi + rdx - 0x20], xmm8
    movdqu      [rdi + 0x20], xmm8
    movdqu      [rdi + rdx - 0x30], xmm8
    movdqu      [rdi + 0x30], xmm8
    movdqu      [rdi + rdx - 0x40], xmm8
    cmp         rdx, 0x80
    jbe         .longend
    movdqu      [rdi + 0x40], xmm8
    movdqu      [rdi + rdx - 0x50], xmm8
    movdqu      [rdi + 0x50], xmm8
    movdqu      [rdi + rdx - 0x60], xmm8
    movdqu      [rdi + 0x60], xmm8
    movdqu      [rdi + rdx - 0x70], xmm8
    movdqu      [rdi + 0x70], xmm8
    movdqu      [rdi + rdx - 0x80], xmm8
    lea         rcx, [rdi + 0x80]
    and         rcx, 0xffffffffffffff80
    add         rdi, rdx
    and         rdi, 0xffffffffffffff80
    cmp         rcx, rdi
    je          .longend
    cmp         rdx, 0x370000
    ja          .verylongloop

.longloop:
    movdqa      [rcx], xmm8
    movdqa      [rcx + 0x10], xmm8
    movdqa      [rcx + 0x20], xmm8
    movdqa      [rcx + 0x30], xmm8
    movdqa      [rcx + 0x40], xmm8
    movdqa      [rcx + 0x50], xmm8
    movdqa      [rcx + 0x60], xmm8
    movdqa      [rcx + 0x70], xmm8
    add         rcx, 0x80
    cmp         rcx, rdi
    jne         .longloop

.longend:
    ret

.verylongloop:
    movntdq     [rcx], xmm8
    movntdq     [rcx + 0x10], xmm8
    movntdq     [rcx + 0x20], xmm8
    movntdq     [rcx + 0x30], xmm8
    movntdq     [rcx + 0x40], xmm8
    movntdq     [rcx + 0x50], xmm8
    movntdq     [rcx + 0x60], xmm8
    movntdq     [rcx + 0x70], xmm8
    add         rcx, 0x80
    cmp         rcx, rdi
    jne         .verylongloop
    ret
