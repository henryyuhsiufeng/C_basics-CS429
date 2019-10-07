# Why Y86? 
Better introduction to assembly level programming than the x86

# Y86 Processor State
There are 5 types of states in the Y86 architecture
1. Processor Registers: Quick access of 64-bit address location in the CPU.
2. Condition Flags: 1-bit flags set by arithmetic or logical operations.
3. Program Counter: Indicates the current address of instruction for the CPU.
4. Memory: Byte-addressable storage Array that follows a little-endian byte order.
5. Status code: Indicate the state of program execution

# fetch-decode-execute cycle / von Neumann architecture
The machine repeats the following forever:
1. fetch the next instruction from memory using the program counter (PC)
2. decode the instruction (happens in the control unit)
3. execute the instruction, updating the state appropriately
4. repeat going back to step 1