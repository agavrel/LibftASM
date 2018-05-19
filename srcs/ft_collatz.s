; credit : johnfound https://stackoverflow.com/questions/40354978/why-is-this-c-code-faster-than-my-hand-written-assembly-for-testing-the-collat

global _ft_collatz

section .text

_ft_collatz:                    ; unsigned int ft_collatz(unsigned int n)
    xor     eax, eax            ; counter = 0

ALIGN 8
.seq:
    inc     eax                 ; ++counter
    lea     edx, [edi * 3 + 1]  ; edx = 3*n+1
    shr     edi, 1              ; edi /= 2
    cmovc   edi, edx            ; if CF eax = edx
    jnz     .seq                ; jmp if n<>1

.res:
    ret

;      About shr cmovc : The original rightmost bit is shifted out of the EAX register into the carry flag (and the new leftmost bit is set to 0). For example:
;
;       +------------------------+               +------------------------+
;       | 1  0  0  1  0  1  0  1 |               | 0  1  1  0  0  1  0  0 |
;       +------------------------+               +------------------------+
;          \  \  \  \  \  \  \  \       or          \  \  \  \  \  \  \  \
;           \  \  \  \  \  \  \  \                   \  \  \  \  \  \  \  \
;       +------------------------+ CF            +------------------------+ CF
;       |(0) 1  0  0  1  0  1  0 | 1             |(0) 0  1  1  0  0  1  0 | 0
;       +------------------------+               +------------------------+
;
