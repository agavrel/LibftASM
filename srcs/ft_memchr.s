
global		_ft_memchr

section .text

_ft_memchr:                 ; void *memchr(const void *s, int c, size_t n);
mov         rax, rdi
