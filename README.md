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

| Bit | Label  | Description  |
| :-----: | :-: | :-: |
| 0 | CF | Carry Flag: Set by arithmetic instructions which generate either a carry or borrow. Set when an operation generates a carry to or a borrow from a destination operand. |
| :-----: | :-: | :-: |
| 2 | PF | Parity Flag: Set by most CPU instructions if the least significant (aka the low-order bits) of the destination operand contain an even number of 1's. Not used much anymore |
| :-----: | :-: | :-: |
| 4 | AF | Auxiliary Carry Flag: Set if there is a carry or borrow involving bit 4 of EAX. Set when a CPU instruction generates a carry to or a borrow from the low-order 4 bits of an operand. This flag is used for binary coded decimal (BCD) arithmetic. |
| :-----: | :-: | :-: |
| 6 | ZF | Zero Flag: Set by most instructions if the result an operation is binary zero. |
| :-----: | :-: | :-: |
| 7 | SF | Sign Flag: Most operations set this bit the same as the most significant bit (MSB) (aka high-order bit) of the result. 0 is positive, 1 is negative. id est: 0xFFFFFFFE is -2, 0xFFFFFFFF is -1 and 0x00000001 is 1. |
| :-----: | :-: | :-: |
| 8 | TF | Trap Flag: (sometimes named a Trace Flag.) Permits single stepping of programs. After executing a single instruction, the processor generates an internal exception 1. When Trap Flag is set by a program, the processor generates a single-step interrupt after each instruction. A debugging program can use this feature to execute a program one instruction at a time. |
| :-----: | :-: | :-: |
| 9 | IF | Interrupt Enable Flag: when set, the processor recognizes external interrupts on the INTR pin. When set, interrupts are recognized and acted on as they are received. The bit can be cleared to turn off interrupt processing temporarily. |
| :-----: | :-: | :-: |
| 10 | DF | Direction Flag: Set and cleared using the STD and CLD instructions. It is used in string processing. When set to 1, string operations process down from high addresses to low addresses. If cleared, string operations process up from low addresses to high addresses. |
| :-----: | :-: | :-: |
| 11 | OF | Overflow Flag: Most arithmetic instructions set this bit, indicating that the result was too large to fit in the destination. When set, it indicates that the result of an operation is too large or too small to fit in the destination operand. |
| :-----: | :-: | :-: |
| 12-13 | IOPL | Input/Output privilege level flags: Used in protected mode to generate four levels of security. |
| :-----: | :-: | :-: |
| 14 | NT | Nested Task Flag: Used in protected mode. When set, it indicates that one system task has invoked another via a CALL Instruction, rather than a JMP. |
| :-----: | :-: | :-: |
| 16 | RF | Resume Flag: Used by the debug registers DR6 and DR7. It enables you to turn off certain exceptions while debugging code. |

#### D - Bigger registers
```
Registers for long double (12 octets) : xmm8 xmm9 xmm10 xmm11
```

## 0x03 - The Stack
The stack grows toward lower memory addresses. Hence the top of the Stack is the lowest numerical address. ESP point to the data that has been used at the top of the stack. 
The stack keeps track of which functions were called before the current one, it holds local variables and is frequently used to pass arguments to the next function to be called.


## 0x04 - Computer Instructions
NOP: The one-byte NOP instruction is in fact an alias mnemonic for the XCHG AX, AX instruction. It is commonly used to align memory to speed-up jump as it is faster to jump using powers of 2.</br>
PUSH: Will push Word (4 bytes), Doubleword (8 bytes) or Quadword (16 bytes) onto the Stack. It can be either an immediate (numeric constant) or the value contained in a register.</br>
The push instruction automatically decrements ESP, the stack pointer, by 4.</br>
CALL: It transfers control to a different function in a way that control can later be resumed where it left off. First it pushes the address of the next instruction onto the stack for use by RET when the function is done.</br>
RET: It pops the top of the stack into EIP register.</br>
MOV: Assign a value from a register, memory or immediate to a register or memory. It can't from memory to memory.</br>
```
