# Why Y86? 
Better introduction to assembly level programming than the x86

# Y86 Processor State
There are 5 types of states in the Y86 architecture
1. Processor Registers: Quick access of 64-bit address location in the CPU.
2. Condition Flags: 1-bit flags set by arithmetic or logical operations.
3. Program Counter: Indicates the current address of instruction for the CPU. 
    - Has the address of the next method to be executed.
4. Memory: Byte-addressable storage Array that follows a little-endian byte order.
5. Status code: Indicate the state of program execution

# fetch-decode-execute cycle / von Neumann architecture
The machine repeats the following forever:
1. fetch the next instruction from memory using the program counter (PC)
2. decode the instruction (happens in the control unit)
3. execute the instruction, updating the state appropriately
4. repeat going back to step 1

# Y86 Instructions
1-1 correspondence
- Machine Language Instructions
    - 1-10 bytes of information read from memory.
        - Can determine instruction length from first byte.
        - Not as many instruction types and simpler encoding than x86-64.
- Each instruction accesses and modififies some part(s) if the program state. 

# Notes from Y86 Assembly Example
- andq   %rdi, %rdi    # test %rdi = n
- irmovq $1, %rdx      # i = 1
    - It is important to declare a constant before you do operations.

# Encoding Registers
Each register has an associated 4-bit ID. Almost the same encoding as in x86-64. %rsp has special functionality. 

# Notes from Sample program
xorq    %rax, %rax          # Sets value in %rax to 0. Could also do irmovq $0, %rax
mrmovq  %0x100(%rax), %rbx  # Memory to memory move. Move what is at %rax to %rbx. You need the parantheses to access the value. 
- Memory to memory move needs a register as an intermediate. 

# Argument Passing
Registers: First 6 arguments
1. %rdi
2. %rsi
3. %rdx
4. %rcx
5. %r8
6. %r9
This convention is for GNU/Linux; Windows is different. 
"Diane's silk dress cost $89"
Push in reverse order! 
Registers are used to pass in parameters. Once the first 6 arguments are filled, the next will be put in a stack. Registers are much faster than memory. 

# Understanding the Addition Instruction
(so whaat's happening???)
[Generic form]:addq rA, rB  [Encoded representation]: 6 0 rA rB
- Add value in register rA to that in register rB.
- addq %rax, %rsi is encoded as: 60 06 why? <------- answer needed
- Set condition codes based on the result. 
- Two byte encoding: 
    - First indicates instruction type. 
    - Second gives source and destination registers. 

# Effects on the State
What effects does addq %rsi, %rdi have on the state?
    - The program counter increases by 2 because it is a two byte instruction. 
    - <--- anything else????????
    