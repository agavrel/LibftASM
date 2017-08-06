global _ft_pow

section .text

_ft_pow:        ; int ft_pow(int x, int y);

; using e(ax) instead of r(ax) as integer is on 4 bytes, 32 bits

    mov eax, 1   	; return value = 1
    cmp esi, 0    	; if exponent = 0
    je	.end        ; then returns 1

    mov ecx, esi    ; ecx (iterator) = esi (y value, exponent)
    xor edx, edx    ; double result = 0;

.while:
    mul edi       	; edx *= edi (x value)

    cmp edx, 0    	; exit if overflow
    jne .error

    loop .while    	; else repeat

.end:
    ret        		; returns eax

.error:
    xor eax, eax    ; returns 0;
    ret
