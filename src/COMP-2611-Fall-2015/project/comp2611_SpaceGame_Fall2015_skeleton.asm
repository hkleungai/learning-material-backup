.data
title: 		.asciiz "COMP2611 Space Game"
game_win:	.asciiz "You Win! Enjoy the game brought by COMP2611!"
game_lose:	.asciiz "Try to improve your skill in the next trial!"
input_Astronaut:.asciiz "Enter the number of Astronauts(in the range [1, 10]): "
input_Alien:	.asciiz "Enter the number of Aliens(in the range [1, 10]): "
input_bombs:	.asciiz "Enter the number of Simple Bombs(in the range [1, 10]): "
input_rbombs:	.asciiz "Enter the number of Remote Bombs(in the range [1, 10]): "
# the level limit is 2
level_title:    .asciiz "Level:"
level_1:        .asciiz "1"
level_2:        .asciiz "2"

width:		.word 800 # the width of the screen
height:		.word 600 # the height of the screen
Alien_ids:	.word -1:50 # used to keep track of the ids of Aliens
Alien_locs:	.word -1:100 # the array of initialized locations of Aliens
Alien_base:	.word 2 # base id of Aliens
Alien_num: 	.word 0 # the number of Aliens
Astronaut_ids:	.word -1:50 # used to keep track of the ids of Astronauts
Astronaut_locs:	.word -1:100 # the array of initialized locations of Astronauts
Astronaut_base:	.word 20 # base id of Astronaut
Astronaut_num: 	.word 0 # the number of Astronauts
bomb_ids: 	.word -1:10 # used to keep track of the ids of bombs
bomb_base:	.word 50 # base id of the simple bomb
bomb_num:	.word 0 # the number of simple bombs
bomb_count:	.word 0 # the number of "running" simple bombs
rbomb_ids:	.word -1:10 # used to keep track of the ids of remote bombs
rbomb_base:	.word 80 # base id of the remote bomb
rbomb_num:	.word 0 # the number of remote bombs
rbomb_count:	.word 0 # the number of "running" remote bombs
game_level:	.word 1 # level of the game, initilized to be 1


.text
main:		addi $sp, $sp, -16
		jal input_game_params # game paras are now in stack, save paras in memory
		lw $t1, 12($sp) # num of Astronaut
		la $t0, Astronaut_num
		sw $t1, 0($t0)		
		lw $t1, 8($sp) # num of Alien
		la $t0, Alien_num
		sw $t1, 0($t0)		
		lw $t1, 4($sp) # num of bombs
		la $t0, bomb_num
		sw $t1, 0($t0)		
		lw $t1, 0($sp) # num of remote bombs
		la $t0, rbomb_num
		sw $t1, 0($t0)		
		addi $sp, $sp, 16
						

		la $a0, title
		la $t0, width
		lw $a1, 0($t0)
		la $t0, height
		lw $a2, 0($t0)
		li $v0, 100 # Create the Game Screen
		syscall
		
		add $a0, $zero, $zero
		addi $a1, $zero, 1
		li $v0, 105
		syscall # play the background sound
			
game_level_init:la $t0, Astronaut_num # load game params for game_init
		lw $a0, 0($t0)
		la $t0, Alien_num
		lw $a1, 0($t0)
		la $t0, bomb_num
		lw $a2, 0($t0)
		la $t0, rbomb_num
		lw $a3, 0($t0)
		
		la $t0, game_level
		lw $fp, 0($t0)
	        li $v0, 124 # set game level
		syscall		
		# if now is level 2, Alien increment by 4
		addi $t2, $zero, 2
		bne $fp, $t2, game_start
		addi $a1, $a1, 4					
		# Initialize the game by create Game Objects based on game level
game_start:     jal init_game	       		
m_loop:		jal get_time
		add $s6, $v0, $zero # $s6: starting time of the game
		jal check_game_end
		bne $v0, $zero, game_end_status
		jal update_object_status	
		jal process_input
		jal check_bomb_hits
		jal move_ship
		jal move_Astronauts
		jal move_Aliens
		jal move_bombs
		jal update_score
		# refresh screen
		li $v0, 119
		syscall
		add $a0, $s6, $zero
		addi $a1, $zero, 30 # iteration gap: 30 milliseconds
		jal have_a_nap
		j m_loop
		
game_end_status: 
                # $v0 hold the game status of current level, $v0 = 1 win, $v0 = 2 lose
                addi $t1, $zero, 1 # $t1 = constant 1
                addi $t2, $zero, 2 # $t2 = constant 2
                beq $v0, $t2, game_over # game over if lose in any level
                # the following handles win at any level
                la $t0, game_level
                lw $t3, 0($t0) # $t3 = current game level
                beq $t3, $t2, win # win at level 2 means win the game
                # if win at level 1, then need to promote to the next level
                sw $t2, 0($t0) # update game_over = 2, promote to level 2
                
                # destroy all bombs in level 1
                jal destroy_bomb            
		# start game level 2
                j game_level_init          
game_over:      
		add $a0, $zero, $zero # stop background sound
		li $v0, 122
		syscall
		addi $a0, $zero, -1 # special id for lose_text
		addi $a1, $zero, 80
		addi $a2, $zero, 280		
		la $a3, game_lose
		li $v0, 104
		syscall # game lose
		li $v0, 119
		syscall # refresh screen
		addi $a0, $zero, 4
		add $a1, $zero, $zero
		li $v0, 105
		syscall
		j game_pause
win:		add $a0, $zero, $zero # stop background sound
		li $v0, 122
		syscall
		addi $a0, $zero, -2 # special id for win_text
		addi $a1, $zero, 80
		addi $a2, $zero, 280
		la $a3, game_win
		li $v0, 104
		syscall # game win
		li $v0, 119
		syscall # refresh screen
		addi $a0, $zero, 4
		add $a1, $zero, $zero
		li $v0, 105
		syscall
game_pause:	add $a0, $s6, $zero
		addi $a1, $zero, 600
		jal have_a_nap
		li $v0, 10
		syscall



#--------------------------------------------------------------------
# func: destroy_bomb
# destroy all the bombs in Java memory
#--------------------------------------------------------------------
destroy_bomb:	
		addi $sp, $sp, -12
		sw $ra, 0($sp)
		sw $s0, 4($sp)
		sw $s1, 8($sp)
		
		# destory simple bombs
		la $s1, bomb_num # $s0 = bomb_num
		lw $s0, 0($s1)
		la $t0, bomb_ids # $t0 = starting address of bomb_ids
		add $t1, $zero, $zero # $t1 = loop counter i
db_loop: 	beq $t1, $s0, destroy_rbomb # finish loop all simple bomb, go to handle remote bomb
		add $t2, $t1, $zero # $t2 = i
		sll $t2, $t2, 2 # $t2 = 4i
		add $t2, $t2, $t0 # $t2 = bomb_ids base + 4i
		lw $a0, 0($t2)	# get bomb id in $a0 and destroy it
		li $v0, 116
		syscall
		addi $t1, $t1, 1
		j db_loop
		# destory remote bombs
destroy_rbomb:	la $s1, rbomb_num # $s0 = rbomb_num
		lw $s0, 0($s1)
		la $t0, rbomb_ids # $t0 = rstarting address of bomb_ids
		add $t1, $zero, $zero # $t1 = loop counter i
drb_loop: 	beq $t1, $s0, destroy_bomb_exit # finish loop all remote bomb, go to clear screen				
		add $t2, $t1, $zero # $t2 = i
		sll $t2, $t2, 2 # $t2 = 4i
		add $t2, $t2, $t0 # $t2 = rbomb_ids base + 4i
		lw $a0, 0($t2)	# get rbomb id in $a0 and destroy it
		li $v0, 116
		syscall
		addi $t1, $t1, 1
		j drb_loop
destroy_bomb_exit:
		lw $ra, 0($sp)
		lw $s0, 4($sp)
		lw $s1, 8($sp)
		addi $sp, $sp, 12
		jr $ra
#--------------------------------------------------------------------
# func: input_game_params
# get the following information interactively from the user:
# 1) number of Astronauts; 2) number of Aliens;
# 3) number of simple bombs; 4) number of remote bombs;
# the results will be placed in the caller's stack space.
#--------------------------------------------------------------------
input_game_params:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		la $a0, input_Astronaut
		li $v0, 4
		syscall # print string
		li $v0, 5
		syscall # read integer
		sw $v0, 16($sp) # store number of Astronauts
		la $a0, input_Alien
		li $v0, 4
		syscall
		li $v0, 5
		syscall
		sw $v0, 12($sp) # store number of Aliens
		la $a0, input_bombs
		li $v0, 4
		syscall
		li $v0, 5
		syscall
		sw $v0, 8($sp) # store number of simple bombs
		la $a0, input_rbombs
		li $v0, 4
		syscall
		li $v0, 5
		syscall
		sw $v0, 4($sp) # store the number of remote bombs
igp_exit:	lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra

#--------------------------------------------------------------------
# func: init_game (num_Astronaut, num_Alien, num_simple_boms, 
#                  num_remote_bombs)
# 1. create the ship: located at the point (320, 440)
# 2. create Astronauts and Aliens; 
#    their locations and directions are randomly fixed.
# 3. init the ids for simple bombs and remote bombs
#--------------------------------------------------------------------
init_game:
	addi $sp, $sp, -20
	sw $ra, 16($sp)
	sw $s0, 12($sp)
	sw $s1, 8($sp)
	sw $s2, 4($sp)
	sw $s3, 0($sp)
	add $s0, $a0, $zero # $s0 = num_Astronaut
	add $s1, $a1, $zero # $s1 = num_Alien
	add $s2, $a2, $zero # $s2 = num_bomb
	add $s3, $a3, $zero # $s3 = num_rbomb
	# 1. create the ship
	li $v0, 101
	li $a0, 1 # the id of ship is 1
	li $a1, 320 # the x_loc of ship
	li $a2, 440 # the y_loc of ship
	li $a3, 4 # set the speed
	syscall
	# 2. create the specified number of Astronauts
	add $a0, $s0, $zero
	jal create_multi_Astronauts
	la $t0, Astronaut_num # keep the record of the num of Astronauts
	sw $s0, 0($t0)
	# 3. create the specified number of Aliens
	add $a0, $s1, $zero
	jal create_multi_Aliens
	la $t0, Alien_num # keep the record of the num of Aliens
	sw $s1, 0($t0)
	# 4. init simple bombs ids and remote bombs ids
	add $a0, $s2, $zero
	add $a1, $s3, $zero
	jal init_bomb_settings	
	# refresh screen
	li $v0, 119
	syscall
ig_exit:
	lw $ra, 16($sp)
	lw $s0, 12($sp)
	lw $s1, 8($sp)
	lw $s2, 4($sp)
	lw $s3, 0($sp)
	addi $sp, $sp, 20
	jr $ra

#--------------------------------------------------------------------
# func create_multi_Astronauts(num)
# @num: the number of Astronauts
# Create multiple Astronauts on the Game Screen.
#--------------------------------------------------------------------
create_multi_Astronauts:
	addi $sp, $sp, -20
	sw $ra, 16($sp)
	sw $s0, 12($sp) # totoal num
	sw $s1, 8($sp) # created num
	add $s0, $a0, $zero
	add $s1, $zero, $zero
cmd_be:	beq $s0, $zero, cmd_exit # whether num <= 0
	# get random x_loc: 4($sp)
	add $a0, $s1, $zero
	jal get_Astronaut_unintersect_xloc
	sw $v0, 4($sp)
	# get random y_loc
	add $a0, $s1, $zero
	jal get_Astronaut_unintersect_yloc
	sw $v0, 0($sp)
	# create one Astronaut
	li $v0, 103
	# calculate id
	la $t0, Astronaut_base
	lw $t1, 0($t0)
	add $a0, $t1, $s1 # set id
	lw $a1, 4($sp)
	lw $a2, 0($sp)
	addi $a3, $zero, 5 # Astronaut speed
	# before syscall, save id, (x_loc, y_loc)
	la $t0, Astronaut_ids
	add $t1, $s1, $zero
	sll $t1, $t1, 2
	add $t1, $t1, $t0
	sw $a0, 0($t1) # save id
	la $t0, Astronaut_locs
	add $t1, $s1, $zero
	sll $t1, $t1, 3
	add $t1, $t1, $t0
	sw $a1, 0($t1) # save x_loc
	sw $a2, 4($t1) # save y_loc
	
	addi $sp, $sp, -12#randomely choose an anstronaut image
	sw $a0, 8($sp)
	sw $a1, 4($sp) 
	sw $v0, 0($sp)
	addi $a1, $zero, 3 
	li $v0, 42
	syscall
	add $t0, $a0, $zero
	lw $a0, 8($sp)
	lw $a1, 4($sp) # totoal num
	lw $v0, 0($sp)
	addi $sp, $sp, 12
	syscall
	
	# to create next one
	addi $s0, $s0, -1
	addi $s1, $s1, 1
	j cmd_be	
cmd_exit:	lw $ra, 16($sp)
		lw $s0, 12($sp)
		lw $s1, 8($sp)
		addi $sp, $sp, 20
		jr $ra

#--------------------------------------------------------------------
# func create_multi_Aliens(num)
# @num: the number of Aliens
# Create multiple Aliens on the Game Screen.
#--------------------------------------------------------------------
create_multi_Aliens:
		addi $sp, $sp, -20
		sw $ra, 16($sp)
		sw $s0, 12($sp) # totoal num
		sw $s1, 8($sp) # created num
		add $s0, $a0, $zero
		add $s1, $zero, $zero
cms_be:		beq $s0, $zero, cms_exit # whether num <= 0
		# get random x_loc: 4($sp)
		add $a0, $s1, $zero
		jal get_Alien_unintersect_xloc
		sw $v0, 4($sp)
		# get random y_loc
		add $a0, $s1, $zero
		jal get_Alien_unintersect_yloc
		sw $v0, 0($sp)
		# create one Alien
		li $v0, 102
		# calculate id
		la $t0, Alien_base
		lw $t1, 0($t0)
		add $a0, $t1, $s1 # set id
		lw $a1, 4($sp)
		lw $a2, 0($sp)
		addi $a3, $zero, 6 # Alien speed
		# before syscall, save id, (x_loc, y_loc)
		la $t0, Alien_ids
		add $t1, $s1, $zero
		sll $t1, $t1, 2
		add $t1, $t1, $t0
		sw $a0, 0($t1) # save id
		la $t0, Alien_locs
		add $t1, $s1, $zero
		sll $t1, $t1, 3
		add $t1, $t1, $t0
		sw $a1, 0($t1) # save x_loc
		sw $a2, 4($t1) # save y_loc
		
		addi $sp, $sp, -12#randomely choose an alien image
		sw $a0, 8($sp)
		sw $a1, 4($sp) 
		sw $v0, 0($sp)
		addi $a1, $zero, 3 
		li $v0, 42
		syscall 
		add $t0, $a0, $zero
		lw $a0, 8($sp)
		lw $a1, 4($sp) # totoal num
		lw $v0, 0($sp)
		addi $sp, $sp, 12
		syscall
		
		addi $s0, $s0, -1 # to create next one
		addi $s1, $s1, 1
		j cms_be	
cms_exit:	lw $ra, 16($sp)
		lw $s0, 12($sp)
		lw $s1, 8($sp)
		addi $sp, $sp, 20
		jr $ra

#--------------------------------------------------------------------
# func get_Astronaut_unintersect_xloc(count):
# Get a random value, used as the x_loc for the newly to be created 
# Astronaut.
# The key is to make sure that it does not intersect with any existing
# Astronauts.
# @count: exisiting number of Astronauts
#--------------------------------------------------------------------
get_Astronaut_unintersect_xloc:
		addi $sp, $sp, -12
		sw $ra, 8($sp)
		sw $s0, 4($sp)
		sw $s1, 0($sp)
		add $s0, $a0, $zero
gdux_loop:	addi $s1, $s0, -1
		li $v0, 42
		li $a0, 50
		li $a1, 700 # the returned random int is in $a0
		syscall
		add $v0, $a0, $zero # now $v0 is the random input
		slt $t1, $s1, $zero
		bne $s1, $zero, gdux_exit
		la $t0, Astronaut_locs
gdux_inner:	sll $t1, $s1, 1 # $t1 = $s1 * 2, now corresponds to x_loc offset in word
		sll $t2, $t1, 2 # $t2: now corresponds to x_loc offset in byte
		add $t1, $t2, $t0 # $t1: now the place where x_loc value is
		lw $t2, 0($t1) # $t2: now the value of x_loc
		# check $v0 and $t2 whether intersect
		slt $t3, $v0, $t2 # if v0 < $t2
		bne $t3, $zero, gdux_label1 # if v0 < $t2 go to gdux_label1
		addi $t2, $t2, 80 # then v0 >= $t2
		slt $t3, $v0, $t2
		bnez $t3, gdux_loop # intersection detected!
		j gdux_nextloop
gdux_label1:	addi $t4, $v0, 80
		slt $t3, $t4, $t2
		beq $t3, $zero, gdux_loop # intersection detected! Restart again!
gdux_nextloop:	addi $s1, $s1, -1
		# check $s1 < 0, if yes, we have founded the need x_loc in $v0
		slt $t3, $s1, $zero
		bnez $t3, gdux_exit
		j gdux_inner
gdux_exit:	lw $ra, 8($sp)
		lw $s0, 4($sp)
		lw $s1, 0($sp)
		addi $sp, $sp, 12
		jr $ra

#--------------------------------------------------------------------
# func get_Astronaut_unintersect_yloc(count):
# Get a random value, used as the y_loc for the newly to be created 
# Astronaut. 
# Constraint: 50<y<350
# The key is to make sure that it does not intersect with any existing
# Astronauts.
# @count: exisiting number of Astronauts
#--------------------------------------------------------------------
get_Astronaut_unintersect_yloc:
		addi $sp, $sp, -12
		sw $ra, 8($sp)
		sw $s0, 4($sp)
		sw $s1, 0($sp)
		add $s0, $a0, $zero
gduy_loop:	addi $s1, $s0, -1
		li $v0, 42
		li $a0, 50
		li $a1, 350 # now $a0 is the random input
		syscall
		add $v0, $a0, $zero # now $v0 is the random input
		slti $t0, $v0, 50
		beq $t0, $zero, gduy_beg
		addi $v0, $v0, 50
		slt $t1, $s1, $zero
gduy_beg:	bne $s1, $zero, gduy_exit
		la $t0, Astronaut_locs
gduy_inner:	sll $t2, $s1, 1 # $t2 = $s1 * 2
		addi $t1, $t2, 1 # $t1: now corresponds to y_loc offset in word
		sll $t2, $t1, 2 # $t2: now corresponds to y_loc offset in byte
		add $t1, $t2, $t0 # $t1: now the place where y_loc value is
		lw $t2, 0($t1) # $t2: now the value of y_loc
		# check $v0 and $t2 whether intersect
		slt $t3, $v0, $t2 # if v0 < $t2
		bne $t3, $zero, gduy_label1 # if v0 < $t2 go to gdux_label1
		addi $t2, $t2, 60 # then v0 >= $t2
		slt $t3, $v0, $t2
		bnez $t3, gduy_loop # intersection detected!
		j gduy_nextloop
gduy_label1:	addi $t4, $v0, 60
		slt $t3, $t4, $t2
		beq $t3, $zero, gduy_loop # intersection detected! Restart again!
gduy_nextloop:	addi $s1, $s1, -1
		# check $s1 < 0, if yes, we have founded the need x_loc in $v0
		slt $t3, $s1, $zero
		bnez $t3, gduy_exit
		j gduy_inner
gduy_exit:	lw $ra, 8($sp)
		lw $s0, 4($sp)
		lw $s1, 0($sp)
		addi $sp, $sp, 12
		jr $ra

#--------------------------------------------------------------------
# func get_Alien_unintersect_xloc(count):
# Get a random value, used as the x_loc for the newly to be created 
# Alien.
# The key is to make sure that it does not intersect with any existing
# Aliens.
# @count: exisiting number of Aliens
#--------------------------------------------------------------------
get_Alien_unintersect_xloc:
		addi $sp, $sp, -12
		sw $ra, 8($sp)
		sw $s0, 4($sp)
		sw $s1, 0($sp)
		add $s0, $a0, $zero
gsux_loop:	addi $s1, $s0, -1
		li $v0, 42
		li $a0, 50
		li $a1, 700 # the returned random int is in $a0
		syscall
		add $v0, $a0, $zero # now $v0 is the random input
		slt $t1, $s1, $zero
		bne $s1, $zero, gsux_exit
		la $t0, Alien_locs
gsux_inner:	sll $t1, $s1, 1 # $t1 = $s1 * 2, now corresponds to x_loc offset in word
		sll $t2, $t1, 2 # $t2: now corresponds to x_loc offset in byte
		add $t1, $t2, $t0 # $t1: now the place where x_loc value is
		lw $t2, 0($t1) # $t2: now the value of x_loc
		# check $v0 and $t2 whether intersect
		slt $t3, $v0, $t2 # if v0 < $t2
		bne $t3, $zero, gsux_label1 # if v0 < $t2 go to gsux_label1
		addi $t2, $t2, 80 # then v0 >= $t2
		slt $t3, $v0, $t2
		bnez $t3, gsux_loop # intersection detected!
		j gsux_nextloop
gsux_label1:	addi $t4, $v0, 80
		slt $t3, $t4, $t2
		beq $t3, $zero, gsux_loop # intersection detected! Restart again!
gsux_nextloop:	addi $s1, $s1, -1
		# check $s1 < 0, if yes, we have founded the need x_loc in $v0
		slt $t3, $s1, $zero
		bnez $t3, gsux_exit
		j gsux_inner
gsux_exit:	lw $ra, 8($sp)
		lw $s0, 4($sp)
		lw $s1, 0($sp)
		addi $sp, $sp, 12
		jr $ra

#--------------------------------------------------------------------
# func get_Alien_unintersect_yloc(count):
# Get a random value, used as the y_loc for the newly to be created 
# Alien. 
# Constraint: 100<y<400
# The key is to make sure that it does not intersect with any existing
# Aliens.
# @count: exisiting number of Aliens
#--------------------------------------------------------------------
get_Alien_unintersect_yloc:
		addi $sp, $sp, -12
		sw $ra, 8($sp)
		sw $s0, 4($sp)
		sw $s1, 0($sp)
		add $s0, $a0, $zero
gsuy_loop:	addi $s1, $s0, -1
		li $v0, 42
		li $a0, 50
		li $a1, 400 # now $a0 is the random input
		syscall
		add $v0, $a0, $zero # now $v0 is the random input
		slti $t0, $v0, 100
		beq $t0, $zero, gsuy_beg
		addi $v0, $v0, 100
		slt $t1, $s1, $zero
gsuy_beg:	bne $s1, $zero, gsuy_exit
		la $t0, Alien_locs
gsuy_inner:	sll $t2, $s1, 1 # $t2 = $s1 * 2
		addi $t1, $t2, 1 # $t1: now corresponds to y_loc offset in word
		sll $t2, $t1, 2 # $t2: now corresponds to y_loc offset in byte
		add $t1, $t2, $t0 # $t1: now the place where y_loc value is
		lw $t2, 0($t1) # $t2: now the value of y_loc
		# check $v0 and $t2 whether intersect
		slt $t3, $v0, $t2 # if v0 < $t2
		bne $t3, $zero, gsuy_label1 # if v0 < $t2 go to gdux_label1
		addi $t2, $t2, 40 # then v0 >= $t2
		slt $t3, $v0, $t2
		bnez $t3, gsuy_loop # intersection detected!
		j gsuy_nextloop
gsuy_label1:	addi $t4, $v0, 40
		slt $t3, $t4, $t2
		beq $t3, $zero, gsuy_loop # intersection detected! Restart again!
gsuy_nextloop:	addi $s1, $s1, -1
		# check $s1 < 0, if yes, we have founded the need x_loc in $v0
		slt $t3, $s1, $zero
		bnez $t3, gsuy_exit
		j gsuy_inner
gsuy_exit:	lw $ra, 8($sp)
		lw $s0, 4($sp)
		lw $s1, 0($sp)
		addi $sp, $sp, 12
		jr $ra
		
#--------------------------------------------------------------------
# func init_bomb_settings(num_bombs, num_rbombs)
# Initialize the "data structure" for simple bombs and remote bombs:
# bomb_ids, bomb_num = @num_bombs, bomb_count = 0;
# rbomb_ids, rbomb_num = @num_rbombs, rbomb_count = 0;
#--------------------------------------------------------------------
init_bomb_settings:
		addi $sp, $sp, -16
		sw $ra, 12($sp)
		sw $s0, 8($sp)
		sw $s1, 4($sp)
		sw $s2, 0($sp)
		add $s0, $a0, $zero # $s0 = num_bombs
		add $s1, $a1, $zero # $s1 = num_rbombs
		la $t0, bomb_num # bomb_num = $a0
		sw $s0, 0($t0)
		la $t0, rbomb_num # rbomb_num = $a1
		sw $s1, 0($t0)
		add $a0, $s0, $zero
		add $a1, $s1, $zero
		li $v0, 123
		syscall # update bomb number info
		la $t0, bomb_count # bomb_count = 0
		sw $zero, 0($t0)
		la $t0, rbomb_count # rbomb_count = 0
		sw $zero, 0($t0)
		# set $s0 ids for bomb_ids
		la $t0, bomb_base
		lw $s2, 0($t0) # $s2 = base_id for simple bomb
		la $t0, bomb_ids # $t0 = starting address of bomb_ids
ibs_bb:		beq $s0, $zero, ibs_be # finish bomb id setting
		addi $t1, $s0, -1
		sll $t1, $t1, 2
		add $t1, $t1, $t0
		sw $s2, 0($t1)
		addi $s2, $s2, 1
		addi $s0, $s0, -1
		j ibs_bb
		# set $s1 ids for rbomb_ids
ibs_be:		la $t0, rbomb_base
		lw $s2, 0($t0) # $s2 = base_id for remote bomb
		la $t0, rbomb_ids # $t0 = starting address of rbomb_ids	
ibs_rb:		beq $s1, $zero, ibs_exit # finish remote bomb id setting
		addi $t1, $s1, -1
		sll $t1, $t1, 2
		add $t1, $t1, $t0
		sw $s2, 0($t1)
		addi $s2, $s2, 1
		addi $s1, $s1, -1
		j ibs_rb
ibs_exit:	lw $ra, 12($sp)
		lw $s0, 8($sp)
		lw $s1, 4($sp)
		lw $s2, 0($sp)
		addi $sp, $sp, 16
		jr $ra

#--------------------------------------------------------------------
# func process_input
# Read the keyboard input and handle it!
#--------------------------------------------------------------------
process_input:	addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal get_keyboard_input # $v0: the return value
		addi $t0, $zero, 115 # corresponds to key 's'
		beq $v0, $t0, pi_emit_bomb
		addi $t0, $zero, 114 # corresponds to key 'r'
		beq $v0, $t0, pi_emit_rbomb
		addi $t0, $zero, 97 # corresponds to key 'a'
		beq $v0, $t0, pi_activate_rbombs
		j pi_exit
pi_emit_bomb:	jal emit_one_bomb
		j pi_exit
pi_emit_rbomb:	jal emit_one_rbomb
		j pi_exit
pi_activate_rbombs:
		jal activate_rbombs
pi_exit:	lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra

#--------------------------------------------------------------------
# func emit_one_bomb
# 1. check whether there are avaiable bombs to use.
# 2. if yes, create one bomb object
#--------------------------------------------------------------------
emit_one_bomb:	addi $sp, $sp, -16
		sw $ra, 12($sp)
		sw $s0, 8($sp)
		sw $s1, 4($sp)
		sw $s2, 0($sp)
		la $t0, bomb_num
		lw $s0, 0($t0)
		la $t0, bomb_count
		lw $s1, 0($t0)
		slt $t1, $s1, $s0
		bne $t1, $zero, eob_go
		j eob_exit
eob_go:		li $a0, 1 # get the location of ship
		li $v0, 110
		syscall
		sub $s0, $v0, 0 # x_loc for the bomb
		sub $s2, $v1, 10 # y_loc for the bomb
		la $t0, bomb_ids # create one bomb object
		sll $t1, $s1, 2
		add $t1, $t0, $t1
		lw $a0, 0($t1) # $a0: the id value to be used
		add $a1, $s0, $zero
		add $a2, $s2, $zero
		addi $a3, $zero, 4 # speed is 4
		li $v0, 106 # create a simple bomb
		syscall
		la $t0, bomb_count
		addi $s1, $s1, 1
		sw $s1, 0($t0) # bomb_count += 1
		la $t0, bomb_num
		lw $t1, 0($t0)
		sub $t1, $t1, $s1 # $t1: the left number of simple bombs
		add $a0, $t1, $zero
		addi $a1, $zero, -1
		li $v0, 123
		syscall # update the number of simple bomb left
		li $v0, 105
		addi $a0, $zero, 2
		add $a1, $zero, $zero
		syscall # play key sound
eob_exit:	lw $ra, 12($sp)
		lw $s0, 8($sp)
		lw $s1, 4($sp)
		lw $s2, 0($sp)
		addi $sp, $sp, 16
		jr $ra	

#--------------------------------------------------------------------
# func emit_one_rbomb
# 1. check whether there are avaiable remote bombs to use.
# 2. if yes, create one remote bomb object
#--------------------------------------------------------------------
emit_one_rbomb:	addi $sp, $sp, -16
		sw $ra, 12($sp)
		sw $s0, 8($sp)
		sw $s1, 4($sp)
		sw $s2, 0($sp)
		la $t0, rbomb_num
		lw $s0, 0($t0)
		la $t0, rbomb_count
		lw $s1, 0($t0)
		slt $t1, $s1, $s0
		bne $t1, $zero, eor_go
		j eor_exit
eor_go:		li $a0, 1 # get the location of ship
		li $v0, 110
		syscall
		sub $s0, $v0, 0 # x_loc for the bomb
		sub $s2, $v1, 10 # y_loc for the bomb
		la $t0, rbomb_ids # create one remote bomb object
		sll $t1, $s1, 2
		add $t1, $t0, $t1
		lw $a0, 0($t1) # $a0: the id value to be used
		add $a1, $s0, $zero
		add $a2, $s2, $zero
		addi $a3, $zero, 4 # speed is 4
		li $v0, 107 # create a remote bomb
		syscall
		la $t0, rbomb_count
		addi $s1, $s1, 1
		sw $s1, 0($t0) # rbomb_count += 1
		la $t0, rbomb_num
		lw $t1, 0($t0)
		sub $t1, $t1, $s1 # $t1: the left number of remote bombs
		add $a1, $t1, $zero
		addi $a0, $zero, -1
		li $v0, 123
		syscall # update the number of remote bomb left	
		li $v0, 105
		addi $a0, $zero, 2
		add $a1, $zero, $zero
		syscall # play key sound
eor_exit:	lw $ra, 12($sp)
		lw $s0, 8($sp)
		lw $s1, 4($sp)
		lw $s2, 0($sp)
		addi $sp, $sp, 16
		jr $ra	

#--------------------------------------------------------------------
# func activate_rbombs
# Activate all the remote bombs: change their status to "activated"!
#--------------------------------------------------------------------
activate_rbombs:
		addi $sp, $sp, -12
		sw $ra, 8($sp)
		sw $s0, 4($sp)
		sw $s1, 0($sp)
		la $t0, rbomb_count
		lw $s0, 0($t0) # $s0: the value of rbomb_count
		la $s1, rbomb_ids
ar_loop:	beq $s0, $zero, ar_exit
		addi $t0, $s0, -1
		sll $t0, $t0, 2
		add $t0, $t0, $s1
		lw $t1, 0($t0)
		beq $t1, $zero, ar_next
		add $a0, $t1, $zero
		li $v0, 109 # activate remote bomb
		syscall
ar_next:	addi $s0, $s0, -1
		j ar_loop
ar_exit:	lw $ra, 8($sp)
		lw $s0, 4($sp)
		lw $s1, 0($sp)
		addi $sp, $sp, 12
		jr $ra

#--------------------------------------------------------------------
# func check_intersection(recA, recB)
# @recA: ((x1, y1), (x2, y2))
# @recB: ((x3, y3), (x4, y4))
# these 8 parameters are passed through stack!
# @params: the coordinates of RectA and RectB are passed through stack.
# 	   In total, 8 words are passed. RectA is followed by RectB, as shown below. 
#	
#	| RectA.topleft_x |
#	| RectA.topleft_y |
#	| RectA.botrigt_x |
#	| RectA.botrigh_y |
#	| RectB.topleft_x |
#	| RectB.topleft_y |
#	| RectB.botrigt_x |
#	| RectB.botrigh_y | <-- $sp 

# This function is to check whether the above two rectangles are intersected!
# @return $v0=1: true(intersect with each other); 0: false
#--------------------------------------------------------------------
check_intersection:
#*****Task2:
# Hints:
# Firstly, load 8 parameters/coordinates from the stack.
# Secondly, check the conditions in which there could be no intersection:
#          condition1: whether recA's left edge is to the right of recB's right edge;
#          condition2: whether recA's right edge is to the left of recB's left edge;
#          condition3: whether recA's top edge is below recB's bottom edge;
#          condition4: whether recA's bottom edge is above recB's top edge.
# Thirdly, set the value of $v0 based on the check result. Then: jr $ra 
#*****You codes start here
		# push preserved registers into stack if needed
		
		# condition1: whether A's left edge is to the right of B's right edge,
		
		# condition2: whether A's right edge is to the left of B's left edge,
		
		# condition3: whether A's top edge is below B's bottom edge,
		
		# conditon4: whether A's bottom edge is above B's top edge,
		
		# pop preserved registers from stack if there are any

#*****Your codes end here





#--------------------------------------------------------------------
# func check_bomb_hits
# 1. For each simple bomb, check whether it hits any Alien
#    or Astronaut.
# 2. For each remote bomb, check whether the activated one hits
#    any Alien or Astronaut.
# 3. The Astronaut will always hurt; but Alien depends!
# 4. update the score value! 
#--------------------------------------------------------------------
check_bomb_hits:
		addi $sp, $sp, -16
		sw $ra, 12($sp)
		sw $s0, 8($sp)
		sw $s1, 4($sp)
		sw $s2, 0($sp)
		la $t0, bomb_count
		lw $s0, 0($t0) # $s0: the number of 'running' simple bombs
		la $s1, bomb_ids
cbh_bn:		beq $s0, $zero, cbh_rb
		addi $t0, $s0, -1
		sll $t0, $t0, 2
		add $t0, $s1, $t0
		lw $s2, 0($t0) # $s2: the id of the simple bomb
		add $a0, $s2, $zero
		jal check_one_bomb_hit
		addi $s0, $s0, -1
		j cbh_bn
cbh_rb:		la $t0, rbomb_count
		lw $s0, 0($t0) # $s0: the number of 'running' remote bombs
		la $s1, rbomb_ids
cbh_rbb:	beq $s0, $zero, cbh_exit
		addi $t0, $s0, -1
		sll $t0, $t0, 2
		add $t0, $s1, $t0
		lw $s2, 0($t0) # $s2: the id of the remote bomb
		# check the status of the bomb: whether it is already activated
		add $a0, $s2, $zero
		li $v0, 108
		syscall
		li $t0, 1
		bne $v0, $t0, cbh_mn
		add $a0, $s2, $zero
		jal check_one_bomb_hit
cbh_mn:		addi $s0, $s0, -1
		j cbh_rbb
cbh_exit:	lw $ra, 12($sp)
		lw $s0, 8($sp)
		lw $s1, 4($sp)
		lw $s2, 0($sp)
		addi $sp, $sp, 16
		jr $ra

#--------------------------------------------------------------------
# check_one_bomb_hit:
# @a0: bomb id
# Given the bomb id, check whether it hits with any Astronaut or
# Alien.
#--------------------------------------------------------------------
check_one_bomb_hit:
		addi $sp, $sp, -28
		sw $ra, 24($sp)
		sw $s0, 20($sp)
		sw $s1, 16($sp)
		sw $s2, 12($sp)
		sw $s3, 8($sp)
		sw $s4, 4($sp)
		sw $s5, 0($sp)
		add $s4, $a0, $zero # $s4: bomb id
		add $s5, $zero, $zero # $s5: whether the bomb is exploded
		li $v0, 110 # get object location
		syscall # $v0: x_loc, $v1: y_loc
		add $s0, $v0, $zero 
		add $s1, $v1, $zero
		# enumerate for each Astronaut
		la $t0, Astronaut_num
		lw $s2, 0($t0) # $s2: the number of Astronauts
cobh_pdb:	beq $s2, $zero, cobh_es
		la $t0, Astronaut_ids
		addi $t1, $s2, -1
		sll $t1, $t1, 2
		add $t1, $t0, $t1
		lw $s3, 0($t1) # $s3: the id of Astronaut
		bne $s3, $zero, cobh_pda # still alive Astronaut
		addi $s2, $s2, -1 # already dead Astronaut (id = 0)
		j cobh_pdb
cobh_pda:	add $a0, $s3, $zero
		li $v0, 110 # get Astronaut location
		syscall	
		addi $sp, $sp, -32
# *****Task1: you need to check if the bomb intersects with the Astronaut.
# You should call procedure: check_intersection to check the intersection.

# Hints:
# The bomb rectangle's top-left point: (x1, y1), x1 is in $s0, y1 is in $s1
# The bomb rectangle's bottom-right point: (x1+30, y1+30)
# The Astronaut rectangle's top-left point: (x2, y2), x2 is in $v0, y2 is in $v1
# The Astronaut rectangle's bottom-right point: (x2+80, y2+60)

# Those points' coordinates should be stored in stack before calling procedure: check_intersection
# @params: the coordinates of RectA(rectangle of bomb) and RectB(rectangle of Astronaut) are passed through stack.
# 	   In total, 8 words are passed. RectA is followed by RectB in the stack, as shown below. 
#	
#	| RectA.topleft_x |
#	| RectA.topleft_y |
#	| RectA.botrigt_x |
#	| RectA.botrigh_y |
#	| RectB.topleft_x |
#	| RectB.topleft_y |
#	| RectB.botrigt_x |
#	| RectB.botrigh_y | <-- $sp 

# *****Your codes start here
		
		
		
		
		
		
		
		
		
		
# *****Your codes end here
                # After calling procedure: check_intersection, $v0=0 if the bomb misses the Astronaut
		beq $v0, $zero, cobh_dsafe # Astronaut is safe
		addi $s5, $s5, 1 # this bomb hits one object
		add $a0, $s3, $zero # deduct Astronaut hit point 10
		li $a1, 10
		li $v0, 114
		syscall # this will cause Astronaut dead
		addi $a0, $zero, 1
		add $a1, $zero, $zero
		li $v0, 105 # play the bomb exploded sound
		syscall
		# (the dead Astronaut will be removed in the next round)	
cobh_dsafe:	addi $sp, $sp, 32
		addi $s2, $s2, -1
		j cobh_pdb
cobh_es:	la $t0, Alien_num # enumerate for each Alien
		lw $s2, 0($t0)
cobh_psb:	beq $s2, $zero, cobh_exit
		la $t0, Alien_ids
		addi $t1, $s2, -1
		sll $t1, $t1, 2
		add $t1, $t0, $t1
		lw $s3, 0($t1) # $s3: the id of Alien
		bne $s3, $zero, cobh_psa # still alive Alien
		addi $s2, $s2, -1 # already dead Alien (id = 0)
		j cobh_psb
cobh_psa:	add $a0, $s3, $zero
		li $v0, 110 # get Alien location
		syscall
		addi $sp, $sp, -32
		# first check whether middle hit
		sw $s0, 28($sp)
		sw $s1, 24($sp) # (x1, y1)
		addi $t0, $s0, 30
		addi $t1, $s1, 30
		sw $t0, 20($sp)
		sw $t1, 16($sp) # (x1+30, y1+30)
		addi $t0, $v0, 35
		add $t1, $v1, $zero
		sw $t0, 12($sp)
		sw $t1, 8($sp) # (x3+35, y3)
		addi $t0, $v0, 45
		addi $t1, $v1, 40
		sw $t0, 4($sp)
		sw $t1, 0($sp) # (x3+45, y3+40)
		jal check_intersection
		bne $v0, $zero, cobh_sdead # Alien is destoryed!
		# further check ordinary case
		add $a0, $s3, $zero
		li $v0, 110 # get Alien location
		syscall
		sw $v0, 12($sp)
		sw $v1, 8($sp) # (x3, y3)
		addi $t0, $v0, 80
		addi $t1, $v1, 40
		sw $t0, 4($sp)
		sw $t1, 0($sp) # (x3+80, y3+40)
		jal check_intersection
		beq $v0, $zero, cobh_scn
		addi $s5, $s5, 1 # this bomb hits one object
		add $a0, $s3, $zero # deduct Alien hit point 5
		li $a1, 5
		li $v0, 114
		syscall
		addi $a0, $zero, 5
		add $a1, $zero, $zero
		li $v0, 105 # play the bomb hit sound
		syscall
		j cobh_scn
cobh_sdead:	addi $s5, $s5, 1 # this bomb hits one object
		add $a0, $s3, $zero
		li $a1, 20
		li $v0, 114
		syscall
		addi $a0, $zero, 1
		add $a1, $zero, $zero
		li $v0, 105 # play the bomb exploded sound
		syscall
cobh_scn:	addi $sp, $sp, 32
		addi $s2, $s2, -1
		j cobh_psb
cobh_exit:	beq $s5, $zero, cobh_return
		# deduct the hit point of the bomb
		add $a0, $s4, $zero
		li $a1, 1
		li $v0, 114
		syscall
cobh_return:	lw $ra, 24($sp)
		lw $s0, 20($sp)
		lw $s1, 16($sp)
		lw $s2, 12($sp)
		lw $s3, 8($sp)
		lw $s4, 4($sp)
		lw $s5, 0($sp)
		addi $sp, $sp, 28
		jr $ra




#--------------------------------------------------------------------
# func: update_score
# The score will be collected from Aliens.
#--------------------------------------------------------------------
update_score:	addi $sp, $sp, -16
		sw $ra, 12($sp)
		sw $s0, 8($sp)
		sw $s1, 4($sp)
		sw $s2, 0($sp)
		add $s2, $zero, $zero # $s2: score
		la $t0, Alien_num
		lw $s0, 0($t0)
us_loop:	beq $s0, $zero, us_exit
		addi $t0, $s0, -1
		sll $t0, $t0, 2
		la $t1, Alien_ids
		add $t0, $t1, $t0
		lw $s1, 0($t0) # the id of the Aliens
		beq $s1, $zero, us_des # already destroyed Alien
		add $a0, $s1, $zero
		li $v0, 115 # get object score
		syscall
		add $s2, $s2, $v0
		addi $s0, $s0, -1
		j us_loop
us_des:		addi $s2, $s2, 20 
		addi $s0, $s0, -1
		j us_loop
us_exit:	add $a0, $s2, $zero
		li $v0, 117
		syscall # update the game score	
# ***** Task4
# ***** Your codes start here. You need to load back the value of $ra, $s0, $s1, $s2 before going out of this function.








# ***** Your codes end here
		jr $ra





#--------------------------------------------------------------------
# func: check_game_end
# Check whether the game is over!
# $v0=0: not end; =1: win; =2: lose
#--------------------------------------------------------------------
check_game_end:
		addi $sp, $sp, -8
		sw $ra, 4($sp)
		sw $s0, 0($sp)
		add $v0, $zero, $zero # $v0: indicates whether any Alien left
		add $v1, $zero, $zero # $v1: indicates whether any Astronaut left
		# check the left number of Aliens
		la $t0, Alien_num
		lw $s0, 0($t0)
cge_sb:		beq $s0, $zero, cge_db # check the left number of Astronaut
		addi $t1, $s0, -1
		sll $t1, $t1, 2
		la $t0, Alien_ids
		add $t1, $t0, $t1
		lw $t0, 0($t1) # $t0: the id of Alien
		beq $t0, $zero, cge_sn
		addi $v0, $zero, 1 # there is still Alien left
		j cge_db
cge_sn:		addi $s0, $s0, -1
		j cge_sb
cge_db:		la $t0, Astronaut_num
		lw $s0, 0($t0)
cge_dbb:	beq $s0, $zero, cge_exit
		addi $t1, $s0, -1
		sll $t1, $t1, 2
		la $t0, Astronaut_ids
		add $t1, $t0, $t1
		lw $t0, 0($t1) # $t0: the id of Astronaut
		beq $t0, $zero, cge_dbn
		addi $v1, $zero, 1 # there is still Astronaut left
		j cge_exit
cge_dbn:	addi $s0, $s0, -1
		j cge_dbb
cge_exit:	beq $v1, $zero, cge_lose# if Astronaut = 0, lose
		beq $v0, $zero, cge_win
		add $v0, $zero, $zero
		j cge_go
cge_win:	addi $v0, $zero, 1
		j cge_go
cge_lose:	addi $v0, $zero, 2
cge_go:		lw $ra, 4($sp)
		lw $s0, 0($sp)
		addi $sp, $sp, 8
		jr $ra
	
#--------------------------------------------------------------------
# func: move_ship
# Move the ship by one step, determined by its speed and direction.
# If the ship is going to cross the boarder, opposite the direction and
# set its location appropriately!
# Eg:=> if x_od + speed > 640; then x_new = 1276 - x_old;
#    <= if x_old - speed < 0; then x_new = 4 - x_old;
# also change the direction
#--------------------------------------------------------------------	
move_ship:	addi $sp, $sp, -12
		sw $ra, 8($sp)
		sw $s0, 4($sp)
		sw $s1, 0($sp)
		li $v0, 110
		li $a0, 1 # id of ship
		syscall
		add $s0, $v0, $zero #xold
		add $s1, $v1, $zero # y
		li $v0, 112 # get direction
		li $a0, 1
		syscall
		add $t0, $v0, $zero
		beq $t0, $zero, ms_left # direction: left; check left border
		# the ship speed is 4, and heads right
		addi $t0, $zero, 636
		slt $t1, $t0, $s0
		bne $t1, $zero, ms_lt
		li $v0, 121 # no need to turn direction, move one step
		li $a0, 1
		syscall 
		j ms_exit
ms_lt: 	 	li $t0, 1276 # turns left
		sub $a1, $t0, $s0
		add $a2, $s1, $zero
		li $v0, 120 # set object location
		li $a0, 1
		syscall
		li $v0, 113
		li $a1, 0 # turn left
		li $a0, 1
		syscall 
		j ms_exit
ms_left:	slti $t0, $s0, 4
		bne $t0, $zero, ms_rt
		li $v0, 121 # no need to turn direction, move one step
		li $a0, 1
		syscall
		j ms_exit
ms_rt:		li $a0, 1 # turn right
		li $t0, 4
		sub $a1, $t0, $s0
		add $a2, $s1, $zero
		li $v0, 120
		syscall
		li $v0, 113
		li $a1, 1 # turn right
		li $a0, 1
		syscall
ms_exit:	lw $ra, 8($sp)
		lw $s0, 4($sp)
		lw $s1, 0($sp)
		addi $sp, $sp, 12
		jr $ra

#--------------------------------------------------------------------
# func: move_Astronauts
# Check the Astronauts one by one to see if they will cross the screen border, and do the related operations 
# If a Astronaut is going to cross the boarder, opposite the direction and
# set its location appropriately!
# Eg: if x_old +speed >= 740 and Astronaut is heading right, then x_new = 1475 - x_old; 
#   or if x_old - speed < 0 and Astronaut is heading left; then x_new = 5 - x_old; ( x_old: the current x-coordinate of the Astronaut)
# Then reverse the heading direction
#--------------------------------------------------------------------	
move_Astronauts:addi $sp, $sp, -16
		sw $ra, 12($sp)
		sw $s0, 8($sp)
		sw $s1, 4($sp)
		sw $s2, 0($sp)
		
		# ***** Task3.1
		# ******Your codes start here. Get the number of Astronauts and store it in $s2




		# ***** Your codes end here.

md_be:		beq $s2, $zero, md_exit
		la $t0, Astronaut_ids # $t0: unchanged till the end
		addi $t1, $s2, -1
		sll $t1, $t1, 2
		add $t2, $t1, $t0 # $t2: the address of id
		lw $t1, 0($t2) # $t1: the id of a Astronaut
		beq $t1, $zero, md_next # if the Astronaut object is destroyed	
		li $v0, 110
		add $a0, $t1, $zero # id of Astronaut
		syscall
		add $s0, $v0, $zero #xold
		add $s1, $v1, $zero # y
		
		# ***** Task3.2
		# ***** Your codes start here. Get the current direction of the Astronaut by using syscall 112. The id of the Astronaut is already in $a0.




		# ***** Your codes end here.

		add $t0, $v0, $zero
		beq $t0, $zero, md_left # direction: left; check left border
		# the Astronaute speed is 5, and heads right
		addi $t0, $zero, 735 
		slt $t1, $t0, $s0 # check if x_old of Astranaut is larger than 740-5=735
		bne $t1, $zero, md_lt
		li $v0, 121 # no need to turn direction, move one step
		syscall 
		j md_next
md_lt:  	li $t0, 1475 # needs to turns left now
		sub $a1, $t0, $s0
		add $a2, $s1, $zero
		li $v0, 120 # set object location
		syscall
		# ***** Task3.3
		# ***** Your codes start here. 
		# you need to change the heading direction of Astronaut as left by using syscall 113. The id of the Astronaut is already in $a0.




		# ***** Your codes end here.
		j md_next
md_left:	slti $t0, $s0, 5
		bne $t0, $zero, md_rt
		li $v0, 121 # no need to turn direction, move one step
		syscall
		j md_next
md_rt:		li $t0, 5 # needs to turn right now
		sub $a1, $t0, $s0
		add $a2, $s1, $zero
		li $v0, 120
		syscall
		# ***** Task3.4
		# ***** Your codes start here. 
		# you need to change the heading direction of Astronaut as right by using syscall 113. The id of the Astronaut is already in $a0. 




		# ***** Your codes end here.
		
md_next:	addi $s2, $s2, -1
		j md_be
md_exit:	lw $ra, 12($sp)
		lw $s0, 8($sp)
		lw $s1, 4($sp)
		lw $s2, 0($sp)
		addi $sp, $sp, 16
		jr $ra



#--------------------------------------------------------------------
# func: move_Aliens
# If a Alien is going to cross the boarder, opposite the direction and
# set its location appropriately!
# Eg:=> if x_old +speed >= 720, then x_new = 1434 - x_old; 
#    <= if x_old - speed < 0; then x_new = 6 - x_old;
# also change the direction
#--------------------------------------------------------------------	
move_Aliens:
		addi $sp, $sp, -16
		sw $ra, 12($sp)
		sw $s0, 8($sp)
		sw $s1, 4($sp)
		sw $s2, 0($sp)
		la $t0, Alien_num
		lw $s2, 0($t0) # $s2: the number of Aliens
mm_be:		beq $s2, $zero, mm_exit
		la $t0, Alien_ids # $t0: unchanged till the end
		addi $t1, $s2, -1
		sll $t1, $t1, 2
		add $t2, $t1, $t0 # $t2: the address of id
		lw $t1, 0($t2) # $t1: the id of a Alien	
		beq $t1, $zero, mm_next
		li $v0, 110
		add $a0, $t1, $zero # id of Alien
		syscall
		add $s0, $v0, $zero #xold
		add $s1, $v1, $zero # y
		li $v0, 112 # get direction
		syscall
		add $t0, $v0, $zero
		beq $t0, $zero, mm_left # direction: left; check left border
		# the Astronaute speed is 6, and heads right
		addi $t0, $zero, 714
		slt $t1, $t0, $s0
		bne $t1, $zero, mm_lt
		li $v0, 121 # no need to turn direction, move one step
		syscall 
		j mm_next
mm_lt:  	li $t0, 1434 # turns left
		sub $a1, $t0, $s0
		add $a2, $s1, $zero
		li $v0, 120 # set object location
		syscall
		li $v0, 113
		li $a1, 0 # turn left
		syscall 
		j mm_next
mm_left:	slti $t0, $s0, 6
		bne $t0, $zero, mm_rt
		li $v0, 121 # no need to turn direction, move one step
		syscall
		j mm_next
mm_rt:		li $t0, 6 # turn right
		sub $a1, $t0, $s0
		add $a2, $s1, $zero
		li $v0, 120
		syscall
		li $v0, 113
		li $a1, 1 # turn right
		syscall
mm_next:	addi $s2, $s2, -1
		j mm_be
mm_exit:	lw $ra, 12($sp)
		lw $s0, 8($sp)
		lw $s1, 4($sp)
		lw $s2, 0($sp)
		addi $sp, $sp, 16
		jr $ra
	
#--------------------------------------------------------------------
# func: move_bombs
# If a bomb is going to cross the bottom, destroy the bomb and
# increase the available number of boms.
# Eg:=> if y_old + speed >= 600, then destory it;
#--------------------------------------------------------------------	
move_bombs:	addi $sp, $sp, -20
		sw $ra, 16($sp)
		sw $s0, 12($sp)
		sw $s1, 8($sp)
		sw $s2, 4($sp)
		sw $s3, 0($sp)
		# process simple bombs
		la $t0, bomb_count
		lw $s0, 0($t0) # $s0: the left number of bombs to move
		add $s3, $s0, $zero # $s3: the last end of the active bomb ids
		la $s1, bomb_ids # $s1: starting address of bomb ids
mb_bb:		beq $s0, $zero, mb_rbb
		addi $t1, $s0, -1
		sll $t1, $t1, 2
		add $t1, $s1, $t1 # $t1: the address of one bomb id
		lw $s2, 0($t1) # $s2: the id of a bomb
		add $a0, $s2, $zero # get bomb location
		li $v0, 110
		syscall # $v0: xloc, $v1: yloc
		slti $t1, $v1, 4
		beq $t1, $zero, mb_mn # if $t1 == 0, simply move one step
		# have to destroy this bomb object
		li $v0, 116 # destory the object
		syscall
		# ! exchage bomb_id[$s0] <-> bomb_id[$s3]
		addi $t0, $s3, -1
		sll $t0, $t0, 2
		add $t0, $s1, $t0
		lw $t2, 0($t0) # $t2 = bomb_id[$s3]
		addi $t3, $s0, -1
		sll $t3, $t3, 2
		add $t3, $s1, $t3
		sw $t2, 0($t3) # bomb_id[$s0] = $t2
		sw $s2, 0($t0) # bomb_id[$s3] = bomb_id[$s0]
		addi $s3, $s3, -1
		la $t0, bomb_count # bomb_count -= 1
		sw $s3, 0($t0)
		la $t0, bomb_num
		lw $t1, 0($t0)
		sub $t1, $t1, $s3 # $t1: the left number of simple bombs
		add $a0, $t1, $zero
		addi $a1, $zero, -1
		li $v0, 123
		syscall # update the number of simple bomb left
		addi $s0, $s0, -1
		j mb_bb
mb_mn:		li $v0, 121
		syscall
		addi $s0, $s0, -1
		j mb_bb
mb_rbb:		# process remote bombs
		la $t0, rbomb_count
		lw $s0, 0($t0) # $s0: the left number of remote bombs to move
		add $s3, $s0, $zero # $s3: the last end of the active remote bomb ids
		la $s1, rbomb_ids # $s1: starting address of remote bomb ids
mb_rb:		beq $s0, $zero, mb_exit
		addi $t1, $s0, -1
		sll $t1, $t1, 2
		add $t1, $s1, $t1 # $t1: the address of one remote bomb id
		lw $s2, 0($t1) # $s2: the id of a remote bomb
		add $a0, $s2, $zero # get remote bomb location
		li $v0, 110
		syscall # $v0: xloc, $v1: yloc
		slti $t1, $v1, 4
		beq $t1, $zero, mb_rmn # if $t1 == 0, simply move one step
		# have to destroy this remote bomb object
		li $v0, 116 # destory the object
		syscall
		# ! exchage rbomb_id[$s0] <-> rbomb_id[$s3]
		addi $t0, $s3, -1
		sll $t0, $t0, 2
		add $t0, $s1, $t0
		lw $t2, 0($t0) # $t2 = rbomb_id[$s3]
		addi $t3, $s0, -1
		sll $t3, $t3, 2
		add $t3, $s1, $t3
		sw $t2, 0($t3) # rbomb_id[$s0] = $t2
		sw $s2, 0($t0) # rbomb_id[$s3] = rbomb_id[$s0]
		addi $s3, $s3, -1
		la $t0, rbomb_count # bomb_count -= 1
		sw $s3, 0($t0)
		la $t0, rbomb_num
		lw $t1, 0($t0)
		sub $t1, $t1, $s3 # $t1: the left number of remote bombs
		add $a1, $t1, $zero
		addi $a0, $zero, -1
		li $v0, 123
		syscall # update the number of remote bomb left
		addi $s0, $s0, -1
		j mb_rb
mb_rmn:		li $v0, 121
		syscall
		addi $s0, $s0, -1
		j mb_rb
mb_exit:	lw $ra, 16($sp)
		lw $s0, 12($sp)
		lw $s1, 8($sp)
		lw $s2, 4($sp)
		lw $s3, 0($sp)
		addi $sp, $sp, 20
		jr $ra

#--------------------------------------------------------------------
# func update_object_status
# 1. if the Astronaut is dead, then destroy the game object;
# 2. if the Alien is destroyed, then destroy the game object;
# 3. if the (r)bomb is already bombed, then destroy the game object;
#--------------------------------------------------------------------
update_object_status:
		addi $sp, $sp, -20
		sw $ra, 16($sp)
		sw $s0, 12($sp)
		sw $s1, 8($sp)
		sw $s2, 4($sp)
		sw $s3, 0($sp)
		# check the Astronaut
		la $t0, Astronaut_num
		lw $s0, 0($t0) # $s0: the number of Astronauts
uos_db:		beq $s0, $zero, uos_sb
		la $t0, Astronaut_ids
		addi $t1, $s0, -1
		sll $t1, $t1, 2
		add $s2, $t0, $t1 # $s2: the address of the id
		lw $s1, 0($s2) # $s1: the id of the Astronaut
		beq $s1, $zero, uos_dd # this Astronaut already died
		add $a0, $s1, $zero
		li $v0, 118
		syscall # get the hit point of Astronaut
		bne $v0, $zero, uos_dd 
		add $a0, $s1, $zero # destroy the Astronaut object
		li $v0, 116
		syscall
		sw $zero, 0($s2) # set the Astronaut_ids[.] = 0
uos_dd: 	addi $s0, $s0, -1
		j uos_db
uos_sb:		# check the Aliens
		la $t0, Alien_num
		lw $s0, 0($t0) # $s0: the number of Aliens
uos_sbb:	beq $s0, $zero, uos_bb
		la $t0, Alien_ids
		addi $t1, $s0, -1
		sll $t1, $t1, 2
		add $s2, $t0, $t1
		lw $s1, 0($s2) # $s1: the id of the Alien
		beq $s1, $zero, uos_sd # this Alien already died
		add $a0, $s1, $zero
		li $v0, 118
		syscall # get the hit point of Alien
		bne $v0, $zero, uos_sd 
		add $a0, $s1, $zero # destroy the Alien object
		li $v0, 116
		syscall
		sw $zero, 0($s2) # set the Alien_ids[.] = 0
uos_sd: 	addi $s0, $s0, -1
		j uos_sbb
uos_bb:		# check the simple bombs
		la $t0, bomb_count
		lw $s0, 0($t0) # $s0: the number of running simple bombs
		add $s3, $s0, $zero # $s3: the last end of active bomb ids
uos_bbb:	beq $s0, $zero, uos_rb
		addi $t1, $s0, -1
		sll $t1, $t1, 2
		la $t0, bomb_ids
		add $t1, $t0, $t1
		lw $s2, 0($t1) # the id of the simple bomb
		add $a0, $s2, $zero 
		li $v0, 118 # get the hit point of the bomb
		syscall
		bne $v0, $zero, uos_bbd
		add $a0, $s2, $zero # destory the bomb object
		li $v0, 116
		syscall
		# ! exchange bomb_ids[$s0] <-> bomb_ids[$s3]
		addi $t0, $s3, -1
		sll $t0, $t0, 2
		la $t1, bomb_ids
		add $t0, $t1, $t0
		lw $t2, 0($t0) # $t2 = bomb_ids[$s3]
		addi $t3, $s0, -1
		sll $t3, $t3, 2
		add $t3, $t1, $t3
		sw $t2, 0($t3) # bomb_ids[$s0] = $t2
		sw $s2, 0($t0) # bomb_ids[$s3] = bomb_ids[$s0]
		addi $s3, $s3, -1
		la $t0, bomb_count
		sw $s3, 0($t0)
		la $t0, bomb_num
		lw $t1, 0($t0)
		sub $t1, $t1, $s3 # $t1: the left number of simple bombs
		add $a0, $t1, $zero
		addi $a1, $zero, -1
		li $v0, 123
		syscall # update the left number of simple bombs
uos_bbd:	addi $s0, $s0, -1
		j uos_bbb
uos_rb:		# check the remote bombs
		la $t0, rbomb_count
		lw $s0, 0($t0) # $s0: the number of running rbombs
		add $s3, $s0, $zero # $s3: the last end of the active rbomb ids
uos_rbb:	beq $s0, $zero, uos_exit
		addi $t1, $s0, -1
		sll $t1, $t1, 2
		la $t0, rbomb_ids
		add $t1, $t0, $t1
		lw $s2, 0($t1) # the id of the remote bomb
		add $a0, $s2, $zero 
		li $v0, 118 # get the hit point of the bomb
		syscall
		bne $v0, $zero, uos_rbd
		add $a0, $s2, $zero # destory the bomb object
		li $v0, 116
		syscall
		# ! exchange rbomb_ids[$s0] <-> rbomb_ids[$s3]
		addi $t0, $s3, -1
		sll $t0, $t0, 2
		la $t1, rbomb_ids
		add $t0, $t1, $t0
		lw $t2, 0($t0) # $t2 = rbomb_ids[$s3]
		addi $t3, $s0, -1
		sll $t3, $t3, 2
		add $t3, $t1, $t3
		sw $t2, 0($t3) # rbomb_ids[$s0] = $t2
		sw $s2, 0($t0) # rbomb_ids[$s3] = rbomb_ids[$s0]
		addi $s3, $s3, -1
		la $t0, rbomb_count
		sw $s3, 0($t0) 
		la $t0, rbomb_num
		lw $t1, 0($t0)
		sub $t1, $t1, $s3 # $t1: the left number of remote bombs
		add $a1, $t1, $zero
		addi $a0, $zero, -1
		li $v0, 123
		syscall # update the left number of remote bombs
uos_rbd:	addi $s0, $s0, -1
		j uos_rbb
uos_exit:	lw $ra, 16($sp)
		lw $s0, 12($sp)
		lw $s1, 8($sp)
		lw $s2, 4($sp)
		lw $s3, 0($sp)
		addi $sp, $sp, 20
		jr $ra
		
		
		

#--------------------------------------------------------------------
# func: get_time
# Get the current time
# $v0 = current time
#--------------------------------------------------------------------
get_time:	li $v0, 30
		syscall # this syscall also changes the value of $a1
		andi $v0, $a0, 0x3FFFFFFF # truncated to milliseconds from some years ago
		jr $ra

#--------------------------------------------------------------------
# func: have_a_nap(last_iteration_time, nap_time)
#--------------------------------------------------------------------
have_a_nap:
	addi $sp, $sp, -8
	sw $ra, 4($sp)
	sw $s0, 0($sp)
	add $s0, $a0, $a1
	jal get_time
	sub $a0, $s0, $v0
	slt $t0, $zero, $a0 
	bne $t0, $zero, han_p
	li $a0, 1 # sleep for at least 1ms
han_p:	li $v0, 32 # syscall: let mars java thread sleep $a0 milliseconds
	syscall
	lw $ra, 4($sp)
	lw $s0, 0($sp)
	addi $sp, $sp, 8
	jr $ra
	
#--------------------------------------------------------------------
# func get_keyboard_input
# $v0: ASCII value of the input character if input is available;
#      otherwise, the value is 0;
#--------------------------------------------------------------------
get_keyboard_input:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		add $v0, $zero, $zero
		lui $a0, 0xFFFF
		lw $a1, 0($a0)
		andi $a1, $a1, 1
		beq $a1, $zero, gki_exit
		lw $v0, 4($a0)
gki_exit:	lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra
