global _ft_isalnum

extern table_type
extern _ft_isdigit
extern _ft_isalpha

section .text

_ft_isalnum:                            ; int ft_isalnum(int c);
  mov rax, rdi
  mov rdx, rdi
  call  _ft_isdigit
  test eax, eax
  jnz .was_a_digit
  lea     rax, [rel table_type]		; Load Effective (memory) Address of table_type in rax
  mov     eax, [rax + rdx]				; rdi is int c, al contains 8 lowest bytes of rax, al = byte[&table_type + c]
  and     eax, 0b00000001					; use mask to check if it is an alpha as defined in table_type

.was_a_digit
  ret

; _ft_isalnum:                            ; int ft_isalnum(int c);
;    lea     rax, [rel table_type]       ; Load Effective (memory) Address of table_type in rax
;    mov     eax, [rax + rdi]         ; rdi is int c, al contains 8 lowest bytes of rax, al = byte[&table_type + c]
;    and     eax, 0b00000011              ; use mask to check if it is an alpha or digit as defined in table_type
;    sete    al
;    ret
