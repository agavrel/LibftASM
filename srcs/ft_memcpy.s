; http://faydoc.tripod.com/cpu/movsb.htm
; http://blog.rewolf.pl/blog/?p=177
; https://stackoverflow.com/questions/43343231/enhanced-rep-movsb-for-memcpy

global		_ft_memcpy

section .text

_ft_memcpy:
mov         rax, rdi

.start:
cmp         rdx, 0x10
jbe         .short
cmp         rdx, 0x40
ja          .long
movdqu      xmm8, [rsi]
movdqu      xmm9, [rsi + rdx - 0x10]
movdqu      [rdi], xmm8
movdqu      [rdi + rdx - 0x10], xmm9
cmp         rdx, 0x20
jbe         .mediumend

.medium:
movdqu      xmm8, [rsi + 0x10]
movdqu      xmm9, [rsi + rdx - 0x20]
movdqu      [rdi + 0x10], xmm8
movdqu      [rdi + rdx - 0x20], xmm9

.mediumend:
ret

.short:
test        dl, 0b11000
jne         .shortlong
test        dl, 0b00100
jne         .shortmedium
test        dl, 0b00001
je          .veryshort
mov         r8b, [rsi]
mov         [rdi], r8b

.veryshort:
test        dl, 0b00010
je          .shortend
mov         r8w, [rsi + rdx - 0x2]
mov         [rdi + rdx - 0x2], r8w

.shortend:
ret

.shortshort:
mov         r8b, [rsi]
mov         r9b, [rsi + rdx - 0x2]
mov         [rdi], r8b
mov         [rdi + rdx - 0x2], r9b
ret

.shortmedium:
mov         r8d, [rsi]
mov         r9d, [rsi + rdx - 0x4]
mov         [rdi], r8d
mov         [rdi + rdx - 0x4], r9d
ret

.shortlong:
mov         r8, [rsi]
mov         r9, [rsi + rdx - 0x8]
mov         [rdi], r8
mov         [rdi + rdx - 0x8], r9
ret

.long:
movdqu      xmm8, [rsi]
movdqu      xmm9, [rsi + rdx - 0x10]
movdqu      xmm10, [rsi + 0x10]
movdqu      xmm11, [rsi + rdx - 0x20]
movdqu      [rdi], xmm8
movdqu      [rdi + rdx - 0x10], xmm9
movdqu      [rdi + 0x10], xmm10
movdqu      [rdi + rdx - 0x20], xmm11
movdqu      xmm8, [rsi + 0x20]
movdqu      xmm9, [rsi + rdx - 0x20]
movdqu      xmm10, [rsi + 0x30]
movdqu      xmm11, [rsi + rdx - 0x30]
movdqu      [rdi + 0x20], xmm8
movdqu      [rdi + rdx - 0x30], xmm9
movdqu      [rdi + 0x30], xmm10
movdqu      [rdi + rdx - 0x40], xmm11
cmp         rdx, 0x80
jbe         .longend
movdqu      xmm8, [rsi + 0x40]
movdqu      xmm9, [rsi + rdx - 0x50]
movdqu      xmm10, [rsi + 0x50]
movdqu      xmm11, [rsi + rdx - 0x60]
movdqu      [rdi + 0x40], xmm8
movdqu      [rdi + rdx - 0x50], xmm9
movdqu      [rdi + 0x50], xmm10
movdqu      [rdi + rdx - 0x60], xmm11
movdqu      xmm8, [rsi + 0x60]
movdqu      xmm9, [rsi + rdx - 0x70]
movdqu      xmm10, [rsi + 0x70]
movdqu      xmm11, [rsi + rdx - 0x80]
movdqu      [rdi + 0x60], xmm8
movdqu      [rdi + rdx - 0x70], xmm9
movdqu      [rdi + 0x70], xmm10
movdqu      [rdi + rdx - 0x80], xmm11
lea         rcx, [rdi + 0x80]
and         rcx, 0xffffffffffffff80
mov         r8, rcx
sub         r8, rdi
add         rsi, r8
add         rdi, rdx
and         rdi, 0xffffffffffffff80
cmp         rcx, rdi
je          .longend
cmp         rdx, 0x370000
ja          .verylongloop

.longloop:
movdqu      xmm8, [rsi]
movdqu      xmm9, [rsi + 0x10]
movdqu      xmm10, [rsi + 0x20]
movdqu      xmm11, [rsi + 0x30]
movdqa      [rcx], xmm8
movdqa      [rcx + 0x10], xmm9
movdqa      [rcx + 0x20], xmm10
movdqa      [rcx + 0x30], xmm11
movdqu      xmm8, [rsi + 0x40]
movdqu      xmm9, [rsi + 0x50]
movdqu      xmm10, [rsi + 0x60]
movdqu      xmm11, [rsi + 0x70]
movdqa      [rcx + 0x40], xmm8
movdqa      [rcx + 0x50], xmm9
movdqa      [rcx + 0x60], xmm10
movdqa      [rcx + 0x70], xmm11
add         rcx, 0x80
add         rsi, 0x80
cmp         rcx, rdi
jne         .longloop

.longend:
ret

.verylongloop:
movdqu      xmm8, [rsi]
movdqu      xmm9, [rsi + 0x10]
movdqu      xmm10, [rsi + 0x20]
movdqu      xmm11, [rsi + 0x30]
movntdq     [rcx], xmm8
movntdq     [rcx + 0x10], xmm9
movntdq     [rcx + 0x20], xmm10
movntdq     [rcx + 0x30], xmm11
movdqu      xmm8, [rsi + 0x40]
movdqu      xmm9, [rsi + 0x50]
movdqu      xmm10, [rsi + 0x60]
movdqu      xmm11, [rsi + 0x70]
movntdq     [rcx + 0x40], xmm8
movntdq     [rcx + 0x50], xmm9
movntdq     [rcx + 0x60], xmm10
movntdq     [rcx + 0x70], xmm11
add         rcx, 0x80
add         rsi, 0x80
cmp         rcx, rdi
jne         .verylongloop
ret
