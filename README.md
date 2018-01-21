# LibftASM - Libc functions (re)coded with assembly language optimizations
## 0x01 - Install, run and debugging
### I - Install NASM (1st line mac / 2nd for Linux):
```
brew install nasm
sudo apt-get install nasm
```
### II - Test library functions
```
bash Usage
(equivalent to 'make test & ./maintest.aout')
```

### III - Use lldb (debugger) to read registers
```
~/.lldbinit
settings set target.x86-disassembly-flavor intel
lldb a.out
b main	; break main
run
b ft_islower ;
c ; continue
s ; step
register read
register read rflags
```


## 0x02 - Computer Architecture

### I - Registers Conventions
There are 8 general purposes registers and 1 Instruction pointer.
EAX is the full 32-bit value with AX is the lower 16-bits, AL is the lower 8 bits, AH is the bits 8 through 15 (zero-based).
Arguments passed to the function are the following: 1st: rdi , 2nd: rsi, 3rd: rdx, 4th: rcx, 5th: r8, 6th: r9. If more params are passed they are stored on the Stack.

#### A - Caller-save registers (eax, ecx, edx)
Caller-saved registers (AKA volatile registers) are used to hold temporary quantities that need not be preserved across calls. For that reason, it is the caller's responsibility to push these registers onto the stack if it wants to restore this value after a procedure call.
```
EAX: Stores function return values 
ECX: Counter for string and loop operation 
EDX: I/O Pointer 
EIP: Instruction pointer (Pointer to the next instruction to be executed) 
```

#### B - Callee-save registers (ebp, ebx, esi, edi)
Callee-saved registers (AKA non-volatile registers) are used to hold long-lived values that should be preserved across calls. When the caller makes a procedure call, it can expect that those registers will hold the same value after the callee returns, making it the responsibility of the callee to save them and restore them before returning to the caller.
```
EBX: Base pointer to the data section 
EDI: Source pointer for string operations 
ESI: Destination pointer for string operations 
ESP: Stack pointer 
EBP: Stack frame base pointer (local variables in the function) 
```

#### C - EFLAGS register
https://en.wikipedia.org/wiki/FLAGS_register
```
Zero Flag (ZF): Set if the result of some instruction was 0, cleared otherwise 
Sign Flag (SF): Set equal to the most-significant bit (MSB) of the result, which is the sign bit of a signed integer (0 if positive, 1 if negative). id est: 0xFFFFFFFE is -2, 0xFFFFFFFF is -1 and 0x00000001 is 1. 
Carry Flag (CF):
```

#### D - Bigger registers
```
Registers for long double (12 octets) : xmm8 xmm9 xmm10 xmm11
```

## 0x03 - The Stack
The stack grows toward lower memory addresses. Hence the top of the Stack is the lowest numerical address. ESP point to the data that has been used at the top of the stack. 
The stack keeps track of which functions were called before the current one, it holds local variables and is frequently used to pass arguments to the next function to be called.


## 0x04 - Computer Instructions
NOP: The one-byte NOP instruction is in fact an alias mnemonic for the XCHG AX, AX instruction. It is commonly used to align memory to speed-up jump as it is faster to jump using powers of 2.
PUSH: Will push Word (4 bytes), Doubleword (8 bytes) or Quadword (16 bytes) onto the Stack. It can be either an immediate (numeric constant) or the value contained in a register. 
The push instruction automatically decrements ESP, the stack pointer, by 4.
CALL: It transfers control to a different function in a way that control can later be resumed where it left off. First it pushes the address of the next instruction onto the stack for use by RET when the function is done. 
RET: It pops the top of the stack into EIP register. 
MOV: Assign a value from a register, memory or immediate to a register or memory. It can't from memory to memory.
```
mov eax, ecx    ; move the value contained in ECX register to EAX, i,e : eax = ecx
```
MOVZX: move a value to bigger container and fill it will the value and 0 for the remaining bits.
```
movzx eax, al   ; move al to eax and fill it with 0
```
LEA: Copy memory address
```
lea rax, [rsi]  ; copy memory address from rsi to rax;
```
TEST: is basically an AND instruction that does not alter the dest.
```
test edx, edx is faster than cmp edx 0, it sets the zero flag to 1 if edx is null, else to 0
```
MOVNTDQ : mov DQ (Double Quadword which means 2 x 4 x 2 = 16 octets = 128 bits) in the source operand (second operand) to the destination operand (first operand) using a non-temporal hint to prevent caching of the data during the write to memory. 


## 0x05 - Must-Read and Must-Watch links
Please read very interesting PDFs in the resources folder of this git<br />
Instructions' List : https://c9x.me/x86<br />
Optimization: http://agner.org/optimize/<br />
About loops: https://stackoverflow.com/questions/47783926/why-are-loops-always-compiled-like-this<br />
Compiler Explorer (git / online version):
https://github.com/mattgodbolt/compiler-explorer /
https://godbolt.org/<br />
[![Great video about compilers & asm](https://img.youtube.com/vi/bSkpMdDe4g4/0.jpg)](https://www.youtube.com/watch?v=bSkpMdDe4g4)<br />
Calling Conventions : https://en.wikipedia.org/wiki/X86_calling_conventions<br />
