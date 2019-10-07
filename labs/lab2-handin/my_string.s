#these are here so that these functions can be called from outside of this file
.globl my_strlen
.globl my_memset
.globl my_strcat
.globl my_strcpy
.globl my_strcspn

my_strlen:
    #lets say I want to use r12 and r13 in these functions. Because they are callee save (the 
    #function that wants to use them must save) we need to push them into the stack, aka,
    #saving them, so we can restore later when we finish
    pushq %r12
    pushq %r13


    ######start of actual code
    #
    #your assembly code for strlen here
    #

    #rax has to have the return value, in the case of strlen, this is the
    #length of the string, this is returning 0 just as a placeholder 
    movq $0, %rax

    ######end of code


    #before returning, we must restore the callee save registers, in opposite
    #order as they were pushed, because this is a stack (first in, last out)
    popq %r13
    popq %r12

    #and return
    ret
    

my_memset:
    movq $0, %rax
    ret

my_strcat:
    movq $0, %rax
    ret

my_strcpy:
    movq $0, %rax
    ret

my_strcspn:
    movq $0, %rax
    ret
