# -*- coding: utf-8 -*-
import numpy as np

class TicTacToeBoard:
    __doc__ = r"""
    A game board for tic-tac-toe.
    * :attr:`board` a two dimensional numpy array of type int.
      It contains only 1 (for first player), -1 (for second player), 0 (empty cell).

    * :attr:`counter` a int records how many steps have been taken in total.

    * :attr:`info` a dict keeps who should make move now as "on_move" 
      and whether the game ends in "terminate".
      Value of "on_move" can either be 1 indicating the first player should make move next
      or -1 indicating it's the second player's turn.

    * :attr:`win_len` indicates the number of marks the corresponding player required to place in a line to win
    
    Args:
        size (tuple of (int, int), optional): The size of the game board, default to be (3, 3)

        length (int, optional): The number of marks the corresponding player required to place in a line to win,
                default to be `min(size)`
    """
    def __init__(self, size=(3, 3), length=None):
        self.board = np.zeros(size, dtype=int)
        self.win_len = length if length else min(size)
        self.counter = 0
        self.info = {"on_move": 1, "terminate": False}

    def _check_board(self):
        """
        Check the status of the board to find if any player places 
        the corresponding mark in a line of length specified.

        Returns:
            winner (int): can be 1 indicating the first player won,
                -1 indicating the second player won,
                or 0, means no winner, possibly tie.

            terminate (bool): tells if the game has end.
        """
        length = self.win_len
        # check if board only contains -1, 0, 1
        assert all(
            map(lambda x: x in [-1, 0, 1], np.unique(self.board))
        ), "Something impossible happened!"

        # check consecutive 1 or -1 using correlate
        ker_h, ker_d = np.ones(length), np.eye(length) #kernel for checking horizonally and diagonally
        #pad to prevent cross-line match
        board_p = np.pad(self.board, pad_width=((0, 0), (0, 1)), mode="constant") 
        ker_d = np.pad(ker_d, pad_width=((0, 0), (0, 1)), mode="constant").flatten()

        hc = np.correlate(board_p.flatten(), ker_h, mode="valid")  # check horizontally
        dc = np.correlate(board_p.flatten(), ker_d, mode="valid")  # check diagonally
        #pad to prevent cross-line match
        board_rp = np.pad(
            np.rot90(self.board), pad_width=((0, 0), (0, 1)), mode="constant"
        )
        vc = np.correlate(board_rp.flatten(), ker_h, mode="valid")  # check vertical
        ac = np.correlate(board_rp.flatten(), ker_d, mode="valid")  # check antidiagonal
        #merge results
        res = np.concatenate((hc, dc, vc, ac))

        #check if match
        p1_win = res.max() == length
        p2_win = res.min() == -length

        assert p1_win != p2_win or p1_win == 0, "Something impossible happened!"
        terminate = p1_win or p2_win or np.all(self.board != 0)
        if p1_win:
            return 1, terminate
        elif p2_win:
            return -1, terminate
        else:
            return 0, terminate

    def reset(self):
        """
        Reset the game board.

        Returns:
            obs (ndarray): the game board, represented in 2d numpy array of type int.
                It contains only 1 (for first player), -1 (for second player), 0 (empty cell).

            reward (tuple of (float, float)): the rewards for the first player and the second player,
                respectively.
            
            info (dict): a dict keeps who should make move now as "on_move" 
                and whether the game ends in "terminate".
                Value of "on_move" can either be 1 indicating the first player should make move next
                or -1 indicating it's the second player's turn.
        """
        self.counter = 0
        self.board[:] = 0
        self.info = {"on_move": 1, "terminate": False}
        return self.board, (0, 0), self.info

    def step(self, player, position):
        """
        Apply action to the game board.

        Args:
            player (int): can either be 1 indicating the first player or -1 indicating the second.

            position (tuple of (int, int)): the coordinates of the position to place the mark.
                Starting from 0.

        Returns:
            obs (ndarray): the game board, represented in 2d numpy array of type int.
                It contains only 1 (for first player), -1 (for second player), 0 (empty cell).

            reward (tuple of (float, float)): the rewards for the first player and the second player,
                respectively.
            
            info (dict): a dict keeps who should make move now as "on_move" 
                and whether the game ends in "terminate".
                Value of "on_move" can either be 1 indicating the first player should make move next
                or -1 indicating it's the second player's turn.
        """
        assert player == self.info["on_move"], "Not this player's turn!"
        assert self.board[position] == 0, "Position already occupied!"
        #set the mark
        self.board[position] = player

        #update counter
        self.counter += 1
        #get reward of 1 if win or -1 if lose and 0 if tie
        p1_reward, terminate = self._check_board()
        p2_reward = -p1_reward
        reward = (p1_reward, p2_reward)

        #switch player
        on_move = -1 if player == 1 else 1

        self.info = {"on_move": on_move, "terminate": terminate}
        return self.board, reward, self.info


class TicTacToe:
    __doc__ = r"""
    A Tic-Tac-Toe game setting.

    * :attr:`player1` a instance of class Player, the first player, must use mark 1.

    * :attr:`player2` a instance of class Player, the second player, must use mark -1.

    * :attr:`board` a instance of TicTacToeBoard.

    Args:
        player1 (Player): the first player.

        player2 (Player): the second player.

        length (int, optional): the number of marks the corresponding player should place in a line to win.
            default to be 3.
        
        size (tuple of (int, int), optional): the game board size, default to be (3, 3).
    """
    def __init__(self, player1, player2, length=3, size=(3, 3)):
        assert length <= min(size)
        self.length = length
        self.board = TicTacToeBoard(size, length)
        self.player1 = player1
        self.player2 = player2

    def run(self):
        """
        Run the game till someone win or tie.

        Returns:
            winner (int): can be 1 indicating the first player won,
                -1 indicating the second player won,
                or 0, means tie.
        """
        obs, _, info = self.board.reset()
        while not info["terminate"]:
            if info["on_move"] == 1:
                action = self.player1.decide(obs)
                obs, (p1_reward, p2_reward), info = self.board.step(1, action)
                self.player1.get_feedback(obs, p1_reward, info, actor=1)
                self.player2.get_feedback(obs, p2_reward, info, actor=1)
            elif info["on_move"] == -1:
                action = self.player2.decide(obs)
                obs, (p1_reward, p2_reward), info = self.board.step(-1, action)
                self.player1.get_feedback(obs, p1_reward, info, actor=-1)
                self.player2.get_feedback(obs, p2_reward, info, actor=-1)
        winner = p1_reward
        return winner
