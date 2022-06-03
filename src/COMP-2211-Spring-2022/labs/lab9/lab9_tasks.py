# -*- coding: utf-8 -*-

# draw current state of the game
def drawboard(board_size, board):
    print('Current state: \n\n')
    for i in range(board_size**2):
        if board[i] == 0:
            print('- ', end=' ') # empty cell
        if board[i] == 1:
            print('X ', end=' ') # mark of AI
        if board[i] == -1:
            print('O ', end=' ') # mark of human
        if (i+1) % board_size == 0:
            print('\n') # move to next line after three elements
    print('\n')

# according to board_size and connect, return the specific winning pattern
# if not defined, return None
def get_win_pattern(board_size, connect):
    winning_pos = None
    # board_size=3, connect=3
    if board_size == 3 and connect == 3:
        winning_pos = [[0,1,2], [3,4,5], [6,7,8], [0,3,6], [1,4,7], [2,5,8], [0,4,8], [2,4,6]]
    # board_size=4, connect=4
    if board_size == 4 and connect == 4:
        winning_pos = [[0,1,2,3], [4,5,6,7], [8,9,10,11], [12,13,14,15], 
                       [0,4,8,12], [1,5,9,13], [2,6,10,14], [3,7,11,15],
                       [0,5,10,15], [3,6,9,12]]
    # board_size=5, connect=5
    if board_size == 5 and connect == 5:
        winning_pos = [[0,1,2,3,4], [5,6,7,8,9], [10,11,12,13,14], [15,16,17,18,19], [20,21,22,23,24],
                       [0,5,10,15,20], [1,6,11,16,21], [2,7,12,17,22], [3,8,13,18,23], [4,9,14,19,24],
                       [0,6,12,18,24], [4,8,12,16,20]]
    # board_size=4, connect=3
    if board_size == 4 and connect == 3:
        winning_pos = [[0,1,2], [1,2,3], [4,5,6], [5,6,7], [8,9,10], [9,10,11], [12,13,14], [13,14,15], 
                       [0,4,8], [4,8,12], [1,5,9], [5,9,13], [2,6,10], [6,10,14], [3,7,11], [7,11,15],
                       [0,5,10], [5,10,15], [1,6,11], [4,9,14], [3,6,9], [6,9,12], [2,5,8], [7,10,13]]

    # board_size=5, connect=3
    if board_size == 5 and connect == 3:
        winning_pos = [[0,1,2], [1,2,3], [2,3,4], [5,6,7], [6,7,8], [7,8,9], 
                       [10,11,12], [11,12,13], [12,13,14], [15,16,17], [16,17,18], [17,18,19], 
                       [20,21,22], [21,22,23], [22,23,24], 
                       [0,5,10], [5,10,15], [10,15,20], [1,6,11], [6,11,16], [11,16,21],
                       [2,7,12], [7,12,17], [12,17,22], [3,8,13], [8,13,18], [13,18,23],
                       [4,9,14], [9,14,19], [14,19,24],
                       [0,6,12], [6,12,18], [12,18,24], [4,8,12], [8,12,16], [12,16,20],
                       [1,7,13], [7,13,19], [5,11,17], [11,17,23], 
                       [3,7,11], [7,11,15], [9,13,17], [13,17,21],
                       [2,8,14], [10,16,22], [2,6,10], [14,18,22]]
    return winning_pos

# check if there is a player wins. If human wins, return -1.
# if AI wins, retun 1. If draw, return 0. If game not finished, return 2.
def check_game(board_size, connect, board):
    # get the pattern for winning
    winning_pos = get_win_pattern(board_size, connect)
    if winning_pos is None:
        print('winning pattern not defined!')
        exit(0)

    # check all possible winning pattern
    num_pattern = len(winning_pos)
    for i in range(num_pattern):
        #############################################################################
        # check each winning pattern, if the same player gets N moves connected, return its mark value (1 or -1)
        # otherwise, do nothing
        # START OF YOUR CODE

        # END OF YOUR CODE
        #############################################################################

    # game not finished if there is at least one empty cell
    if any(element == 0 for element in board):
        return 2
    # it's a draw
    return 0

# obtain user's input and update the board
def human_turn(board_size, board):
    pos = input("Enter O's position [1 to {}]: ".format(board_size**2))
    pos = int(pos)
    # if input is illegal (either out of range or already taken), ask user to input again
    while(pos<1 or pos >board_size**2 or board[pos-1]!=0):
        print('Illegal move! Try again...')
        pos = input("Enter O's position [1 to {}]: ".format(board_size**2))
        pos = int(pos)   

    # the move is legal, then put -1 for human player
    board[pos-1] = -1

# perform minimax search
def minimax(board_size, connect, board, player):
    result = check_game(board_size, connect, board) # check if any player wins

    #############################################################################
    # if terminal state is achieved, return the terminal result
    # otherwise, call minimax recursively to find values of all possible moves
    # then return the max/min value according to the player
    # shall be easy, just adapt the one from the lecture 
    # make it compatible to different board_size and connect
    # START OF YOUR CODE

    # END OF YOUR CODE
    #############################################################################

# perform minimax search with alpha-beta pruning
def minimax_abp(board_size, connect, board, player, alpha=-float('inf'), beta=float('inf')):
    result = check_game(board_size, connect, board) # check if any player wins
    #############################################################################
    # if terminal state is achieved, return the terminal result
    # otherwise, call minimax recursively, and use alpha-beta pruning to save computation
    # return the min/max value
    # START OF YOUR CODE

    # END OF YOUR CODE
    #############################################################################

# perform minimax search with alpha-beta pruning, the depth of tree also affects values
def minimax_abpd(board_size, connect, board, player, alpha=-float('inf'), beta=float('inf'), depth=0):
    result = check_game(board_size, connect, board) # check if any player wins
    #############################################################################
    # if terminal state is achieved, return the terminal result
    # if AI is winning, the returned value should be larger for a smaller depth (depth=0 for root, depth=1 for first-level, etc.)
    # if AI is losing, the returned value should be larger for a larger depth
    # START OF YOUR CODE

    # END OF YOUR CODE
    #############################################################################

# it's AI's turn to make a move
def ai_turn(board_size, connect, board, strategy):
    pos = -1 # initialize pos to illegal value, -1 here
    max_value = -2 # initialize max value so far to -2, which is a value smaller than possible min value

    for i in range(board_size**2):
        if board[i] == 0: # if the cell is empty
            board[i] = 1 # try to put X at cell i+1
            if strategy == 'minimax': # use minimax as strategy
                score = minimax(board_size, connect, board, -1) # calculate minimax score for human player 
            elif strategy == 'minimax_abp': # use minimax with alpha-beta pruning as strategy
                score = minimax_abp(board_size, connect, board, -1) # calculate minimax score for human player 
            elif strategy == 'minimax_abpd': # use minimax with alpha-beta pruning as strategy, the depth of tree also affects values
                score = minimax_abpd(board_size, connect, board, -1) # calculate minimax score for human player
            else:
                print('No such strategy!')
                exit(0)
            board[i] = 0 # undo the trail
            if score > max_value: # if we can get a better score in next level, 
                max_value = score # update the score and pos
                pos = i
    return pos # return the best move

if __name__ == '__main__':
    # this cell is the code for interactive UI
    
    #board_size = 3 # size of the board
    #connect = 3 # how many connect to win
    board_size = 4 # size of the board
    connect = 3 # how many connect to win
    
    # we will implement three strategies, namely 
    # 1. minimax  
    # 2. minimax_abp (with alpha-beta pruning)  
    # 3. minimax_abpd (further take depth into account)
    #strategy = 'minimax'
    #strategy = 'minimax_abp'
    strategy = 'minimax_abpd'
    
    # the board is represented in a single dimensional list
    # initialize the board to all zeros (i.e., empty cells)
    board = [0] * board_size**2
    
    print('AI: X vs. You: O')
    first = input('Play first (Y/N) :')
    if first == 'Y' or first == 'y':
        player = -1 # human plays first
    else:
        player = 1 # AI plays first
    
    # loops with possible largest iterations
    for i in range(board_size**2+1):
        # check if reaches terminal state
        result = check_game(board_size, connect, board)
        if result != 2: # reaches terminal state
            if result == 0:
                drawboard(board_size, board)
                print('Draw!!!')
            if result == 1:
                drawboard(board_size, board)
                print('AI(X) wins!!!')
            if result == -1:
                drawboard(board_size, board)
                print('Human(O) wins!!!')
            break # stop the loop to end the game
    
        if player == 1: # AI's turn
            pos = ai_turn(board_size, connect, board, strategy)
            board[pos] = 1
            player *= -1 # switch the turn after making a move
        else: # human's turn
            drawboard(board_size, board)
            human_turn(board_size, board)
            player *= -1 # switch the turn after making a move
    
    # here are some cases for separately testing the correctness, especially for the larger board size
    # board = [ 0,  0,  0,  0,  0,
    #           0,  0,  0,  0,  0,
    #           0,  0,  0,  0,  0,
    #           0,  0,  0,  0,  0,
    #           0,  0,  0,  0,  0]
    # # board_size=5, connect=3          
    # board = [-1,  0, -1,  0,  0,
    #          -1,  1,  0,  0,  0,
    #           1, -1,  1,  0,  0,
    #           0,  0,  0,  0,  0,
    #           0,  1,  0,  0, -1]
    # # board_size=5, connect=5          
    # board = [-1,  0, -1,  0,  1,
    #          -1,  1,  0,  1,  0,
    #          -1, -1,  1,  0,  0,
    #          -1,  1,  0,  0,  0,
    #           0,  1,  0,  0, -1]
    # # board_size=4, connect=4          
    # board = [-1, 0, 0, 0,
    #          -1, 1, 0, 0,
    #          -1, 0, 1, 0,
    #           0, 0, 0, 0]
    # # board_size=4, connect=3          
    # board = [-1, 0, 0, 0,
    #          -1, 1, 0, 0,
    #           0, 0, 1, 0,
    #           0, 0, 0, 0]
    # pos = ai_turn(board_size, connect, board, 'minimax_abp')
    # print(pos)
