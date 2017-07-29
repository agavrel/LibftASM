;Intel x64 Assembly Instructions Infos. Credit : jguyet
;-------------------------------------------------------------------------------
;Instruction |   arg1    |   arg2   |comments
mov           dest       ,src       ;dest <-- src
movzx         dest       ,src       ;extension avec des 0 dans dest
movsx         dest       ,src       ;extension avec le bit de signe dans dest
movsd         dest       ,src       ;dest(double) <-- src(float)
movss         dest       ,src       ;dest(float) <-- src(float)
              ;tailles possibles :
              ;byte     | 1 octet
              ;word     | 2 octets ou 1 mot
              ;dword    | 2 mots
              ;qword    | 4 mots
              ;tword    | 10 octets
              ;On utilise la taille pour lever l’ambigu¨ıt´e dans les instructions
              ;quand c’est n´ecessaire
lea           dest        ,[op]     ;dest <-- adresse de op (load effective address)
push          op                    ;decremente [rsp de 8] et ajoute op sur la pile de taille qword (64bits)
pop           op                    ;incremente [rsp de 8] et retire op de la pile de taille qword (64bits)

lea           esi,        [input]   ;(1)ESI = address input_string
lea           edi,        [output]  ;(2)ESI = address input_string
movsb                               ;(3)copy 1 byte from [ESI] to [EDI]
movsw                               ;(3)copy 2 byte from [ESI] to [EDI
movsd                               ;(3)copy 4 byte from [ESI] to [EDI
;100goctet 100gbits
;OPERATORS (fini par "sd" si (double)) (fini par "ss" si (float))
add           op1         ,op2                    ;op1 <-- op1 + op2
sub           op1         ,op2                    ;op1 <-- op1 - op2
imul          op1         ,op2                    ;op1 <-- op1 * op2
imul          op1         ,op2      ,op3          ;op1 <-- op2 * op3
idiv          op1         ,op2                    ;op1 <-- op1 / op2
inc           op                                  ;op  <-- op + 1
dec           op                                  ;op  <-- op - 1
neg           reg                                 ;reg <-- -reg
and           op1         ,op2                    ;op1 <-- op1 & op2
or            op1         ,op2                    ;op1 <-- op1 | op2
xor           op1         ,op2                    ;op1 <-- op1 ^ op2
not           reg                                 ;reg <-- reverse bits of reg
shl           reg         ,op2                    ;reg <-- reg << op2
shr           reg         ,op2                    ;reg <-- reg >> op2
sal           reg         ,op2                    ;reg <-- reg << op2
sar           reg         ,op2                    ;reg <-- reg >> op2
rol           reg         ,op2                    ;reg <-- reg decalageCirculaireGaucheDe op2
ror           reg         ,op2                    ;eg <-- reg decalageCirculaireDroiteDe op2
rcl           reg         ,op2                    ;reg:CF <-- reg:CF decalageCircGauchede op2
rcr           reg         ,op2                    ;reg:CF <-- reg:CF decalageCircDroitede op2


;CONDITIONS Actions
cmp           op1         ,op2      ;(1)a faire en premier
jmp           op                    ;(1)branchement inconditionnel a ladresse op
;-------------------------------------------------------------------------------
je            op                    ;(2)branchement a l’adresse op si op1 = op2
jne           op                    ;(2)branchement a l’adresse op si op1 != op2
jl            op                    ;(2)branchement a l’adresse op si op1 < op2
jle           op                    ;(2)branchement a l’adresse op si op1 <= op2
jg            op                    ;(2)branchement a l’adresse op si op1 > op2
jge           op                    ;(2)branchement a l’adresse op si op1 >= op2
;------------------------------VOIR RFLAGS--------------------------------------
jz            op                    ;(2)branchement a l’adresse op si ZF=1
jnz           op                    ;(2)branchement a l’adresse op si ZF=0
jo            op                    ;(2)branchement a l’adresse op si OF=1
jno           op                    ;(2)branchement a l’adresse op si OF=0
js            op                    ;(2)branchement a l’adresse op si SF=1
jns           op                    ;(2)branchement a l’adresse op si SF=0
jc            op                    ;(2)branchement a l’adresse op si CF=1
jnc           op                    ;(2)branchement a l’adresse op si CF=0
jp            op                    ;(2)branchement a l’adresse op si PF=1
jnp           op                    ;(2)branchement a l’adresse op si PF=0
;-------------------------------------------------------------------------------

cmp           reg1        ,reg2     ;(1)
ja            function              ;(2)(ce referer au registre rflags)jumps if CF = 0 and ZF = 0

cmp           reg1        ,reg2     ;(1)
jg            function              ;(2)(ce referer au registre rflags) jumps if ZF = 0 and SF = OF


;ecrire un message dans un file descriptor
mov           rsi         ,message  ;(1)set le pointer a afficher
mov           rdx         ,len      ;(2)set la longueur a afficher
mov           rdi         ,1        ;(3)signifie un envoie dans stdout 1
mov           rax         ,0x2000004;(4)appel de la function system write et retour dans
syscall                             ;(5)lancement de lappel de function system

;if else exemple :
if:           cmp op1,op2           ;(1)condition
              jg  else              ;(2)si op1 < op2 ont vas dans else
              ;code
              jmp endif             ;ont par a la fin pour eviter de rentrer dans le else
else:
              ;code
endif:
