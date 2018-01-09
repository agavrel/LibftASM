# LibftASM
## libc functions coded with assembly language
Install NASM (1st line mac / 2nd for Linux):
```
brew install nasm
sudo apt-get install nasm
```
Test library functions :
```
make test
```
Some useful explanations on asm keywords:
```
https://c9x.me/x86
https://en.wikipedia.org/wiki/X86_calling_conventions
1) Arguments passed to the function are the following: 1st: rdi , 2nd: rsi, 3rd: rdx, 4th: rcx, 5th: r8, 6th: r9. If more params are passed they are stored on the Stack.
2) Function's return value: ax for 16 bits, eax 32 bits, and rax 64 bits.
3) EAX is the full 32-bit value with AX is the lower 16-bits, AL is the lower 8 bits, AH is the bits 8 through 15 (zero-based)
4) Registers for long double (12 octets) : xmm8 xmm9 xmm10 xmm11
5) Comparing with 0: {test edx, edx} is faster than {cmp edx 0}, it sets the zero flag to 1 if edx is null, else to 0
6) movzx eax, al : move al to eax and fill it with 0
7) MOVNTDQ : mov DQ (Double Quadword which means 2 x 4 x 2 = 16 octets = 128 bits) in the source operand (second operand) to the destination operand (first operand) using a non-temporal hint to prevent caching of the data during the write to memory.
8) Copy memory address : lea rax, [rsi]: copy memory address from rsi to rax;
```
