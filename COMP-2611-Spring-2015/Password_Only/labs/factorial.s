.data
msg: .asciiz "Enter the value n:"

.text
.globl main

main:
#print a string                  
li $v0, 4                
la $a0, msg
syscall

#read an integer into $v0
li $v0, 5
syscall

#$v0 contains n, now 
add $a0,$v0,$zero
#calculate the factorial(n)
jal factorial

#copy the result to $a0
#output the result and terminate
add $a0, $v0, $zero
li $v0,1 
syscall
j end

factorial:

base_case:                           # Base Case
slti $t0, $a0, 2                     # n<2 (if true n<=1)
bne $t0, 1, non_base_case  # n >=2, jump to the part for the non-base case
addi $v0, $zero, 1               #  n<2,    do the calculation for the base case 
jr $ra                                   # return to the caller


non_base_case:                  # Non Base Case
addi $sp, $sp, -8                 # Move the stack pointer down by 2 words
sw $a0, 4($sp)                   # push $a0=n to the stack
sw $ra, 0($sp)                    # push $ra to the stack

addi $a0, $a0, -1               # reduce n before calling factorial 
jal factorial                        # recursively call factorial to cal factorial(n-1)

lw $a0, 4($sp)                  # pop n=$a0 after the call to factorial(n-1)
lw $ra, 0($sp)                   # pop $ra after the call to factorial(n-1) 
addi $sp, $sp, 8                # update the stack pointer (free 2 words)
multu $a0, $v0                 # calculate n*f(n-1) and store in $v0 
mflo $v0                           #
jr $ra                                # return to the caller
end:
