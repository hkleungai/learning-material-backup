.data
    prompt: .asciiz "Input an integer N:\n"
    result: .asciiz "Factorial(N) = "

.text
.globl main

main:
     # show prompt
    li        $v0, 4
    la        $a0, prompt
    syscall
    # read x
    li        $v0, 5
    syscall
	
    # function call
    move      $a0, $v0		 #  $a0 contains the read in integer (i.e. N)
    jal      factorial       # call factorial(N) 
    move      $t0, $v0       # $t0 = $v0;$v0 contains the result of factorial(N)
	
    # show prompt
    li        $v0, 4
    la        $a0, result
    syscall
    # print the result
    li        $v0, 1        # system call #1 - print int
    move      $a0, $t0      # $a0 = $t0
    syscall                 # execute
    # return 0
    li        $v0, 10        # $v0 = 10
    syscall


factorial:
	addi $sp, $sp, -4	#push $ra
	sw $ra, 0($sp)

base_case:			
	bne $a0, $zero, recursive_case	# if N>=1, f(N) = N * f(N-1)
	addi $v0, $zero, 1	# return f(0) = 1
	j factorial_exit

recursive_case:
	addi $sp, $sp, -4	# push $a0 (to save value N), caller's role
	sw $a0, 0($sp)		

	addi $a0, $a0, -1	# now $a0 = N-1
	jal factorial		# call f(N-1)
				# when factorial returns, f(N-1) is in $v0
	lw $a0, 0($sp)		# pop value N from stack
	addi $sp, $sp, 4
	mult $a0, $v0		# f(N) = N * f(N-1)
	mflo $v0		# now $v0 holds f(N)

factorial_exit:
	lw $ra, 0($sp)		# pop return address $ra
	addi $sp, $sp, 4
	jr $ra

	
