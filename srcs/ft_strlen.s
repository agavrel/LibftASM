; http://tuttlem.github.io/2013/01/08/strlen-implementation-in-nasm.html

global _ft_strlen

section .text

_ft_strlen:
	mov			rax, rdi				; rdi c'est la str
	pxor		xmm9, xmm9
	pxor		xmm10, xmm10
	pxor		xmm11, xmm11

.alignement: ; on aligne la str
	movdqu		xmm8, [rax]				; met [rax] dans xmm8 meme si c'est pas aligné
	pcmpeqb		xmm8, xmm9				; si [rax] a un octet égal à 0, l'octet correspondant de xmm8 sera set à 0xff
	pmovmskb	edx, xmm8				; tout les premiers bits de chaque octets de xmm8 sont copié dans les 16 derniers bits de edx
	test		edx, edx
	jz			_ft_strlen.avant_boucle
	xor			rax, rax
	bsf			eax, edx				; renvoie la position du 1 le plus à droite
	ret

.avant_boucle:
	and			rax, 0xfffffffffffffff0 ; aligne la str sur 16 octets
    pcmpeqb  	xmm9, [rax + 0x10]
    pcmpeqb  	xmm10, [rax + 0x20]
    pcmpeqb  	xmm11, [rax + 0x30]
    pmovmskb 	esi, xmm9
    pmovmskb 	ecx, xmm10
    pmovmskb 	r8d, xmm11
	shl			rsi, 0x10				; rsi << 16
	shl			r8, 0x10
	or			r8, rcx
	shl			r8, 0x20
	or			r8, rsi					; tout est mis sur un seul registre, l'ordre est important
	mov			rcx, rdi
	xor			rcx, rax
	and			rax, 0xffffffffffffffc0 ; aligne la str sur 64 octets
	sar			r8, cl					; r11 >> cl, pour compenser l'aligement
	test		r8, r8
	je			_ft_strlen.boucle
	bsf			rax, r8
	ret

.boucle:	; on cherche le 0
	add			rax, 0x40
	movdqa		xmm8, [rax]				; met [rax] dans xmm8 si c'est aligné
	pminub		xmm8, [rax + 0x10]		; pour chaque octet, prend le plus petit des 2
	pminub		xmm8, [rax + 0x20]
	pminub		xmm8, [rax + 0x30]
	pcmpeqb		xmm8, xmm9
	pmovmskb	edx, xmm8
	test		edx, edx
	jz			_ft_strlen.boucle

.end: ; on sait qu'il y a un 0 mais pas encore où
	pxor		xmm8, xmm8
	pcmpeqb		xmm8, [rax]
	pcmpeqb 	xmm9, [rax + 0x10]
	pcmpeqb 	xmm10, [rax + 0x20]
	pcmpeqb 	xmm11, [rax + 0x30]
	pmovmskb	esi, xmm8
	pmovmskb	edx, xmm9
	pmovmskb	ecx, xmm10
	pmovmskb	r8d, xmm11
	shl			rdx, 0x10
	shl			r8, 0x10
	or			rdx, rsi
	or			r8, rcx
	shl			r8, 0x20
	or			r8, rdx
	sub			rax, rdi
	bsf			rcx, r8
	add			rax, rcx
	ret
