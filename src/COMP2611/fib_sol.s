.data
msg1:.asciiz "Enter the value n:"

.text
.globl main

main:
#print a string
li $v0,4
la $a0,msg1
syscall 
#read an int
li $v0,5
syscall 
#store the int to $a0
add $a0,$v0,$zero 

jal fib #call fib

add $a0,$v0,$zero
li $v0,1
syscall

li $v0,10
syscall

fib:

#return( fib(n-1)+fib(n-2) ) in $v0
addi $sp,$sp,-12 #save in stack
sw $ra,0($sp)
sw $s0,4($sp)
sw $s1,8($sp)

add $s0,$a0,$zero

addi $t1,$zero,1
beq $s0,$zero,return0
beq $s0,$t1,return1

addi $a0,$s0,-1

jal fib

add $s1,$zero,$v0     #s1=fib(n-1)

addi $a0,$s0,-2

jal fib               #v0=fib(n-2)

add $v0,$v0,$s1       #v0=fib(n-2)+$s1

exitfib:
lw $ra,0($sp)       #read registers from stack
lw $s0,4($sp)
lw $s1,8($sp)
addi $sp,$sp,12       #bring back stack pointer
jr $ra

return1:
li $v0,1
j exitfib

return0:     
li $v0,0
j exitfib