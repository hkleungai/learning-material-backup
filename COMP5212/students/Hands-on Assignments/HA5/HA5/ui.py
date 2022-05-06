# -*- coding: utf-8 -*-
import os, sys

class TicTacToeUI:
    __doc__ = r"""
    A base UI class, define the interface.

    * :attr:`mark` keeps the role of player, can either be 1 (for the first player),
      or -1 (for the second).

    * :attr:`board_size` the size of the game board, in tuple of (int, int).

    Args:
        mark (int): the role of player, can either be 1 (for the first player),
        or -1 (for the second).

        board_size (tuple of (int, int)): the size of the game board, default to be (3, 3).
    """
    def __init__(self, mark, board_size=(3, 3)):
        assert mark in [1, -1]
        self.mark = mark
        self.board_size = board_size

    def render(self, obs):
        """
        render the game board.

        Args:
            obs (ndarray): a 2D numpy array, filled with 1, -1, 0,
                indicating mark of first player, second player, and place not yet occupied.
        """
        raise NotImplementedError

    def get_action(self):
        """
        get user's input and return the action.

        Returns:
            action (tuple of (int, int)): indicates the coordinates to place mark,
                starting from 0, i.e. (0, 0) is the top left corner.
        """
        raise NotImplementedError

    def set_winner(self):
        """
        claim winner of the game.
        """
        raise NotImplementedError

    def set_loser(self):
        """
        claim loser of the game.
        """
        raise NotImplementedError
    
    def set_tie(self):
        """
        claim tie.
        """
        raise NotImplementedError


class TicTacToeTUI(TicTacToeUI):
    __doc__ = r"""
    A UI in terminal

    * :attr:`mark` keeps the role of player, can either be 1 (for the first player),
      or -1 (for the second).

    * :attr:`board_size` the size of the game board, in tuple of (int, int).

    * :attr:`mark_map` a dict map 1, -1, 0 to corresponding mark. X for 1, O for -1, empty for 0.

    Args:
        mark (int): the role of player, can either be 1 (for the first player),
        or -1 (for the second).

        board_size (tuple of (int, int)): the size of the game board, default to be (3, 3).
    """
    def __init__(self, mark, board_size=(3, 3)):
        super(TicTacToeTUI, self).__init__(mark, board_size)
        self.mark_map = {1: " X ", -1: " O ", 0: "   "}

    def render(self, obs):
        """
        render the game board.

        Args:
            obs (ndarray): a 2D numpy array, filled with 1, -1, 0,
                indicating mark of first player, second player, and place not yet occupied.
        """
        self.clean()
        h, w = obs.shape
        assert (h, w) == self.board_size, "Size does not match!"
        rows = map(lambda x: "|".join(map(lambda y: self.mark_map[y], x)), obs)
        splitter = "+".join(["---"] * w)
        print(("\n" + splitter + "\n").join(rows))
        print()

    def get_action(self):
        """
        get user's input and return the action.

        Returns:
            action (tuple of (int, int)): indicates the coordinates to place mark,
                starting from 0, i.e. (0, 0) is the top left corner.
        """
        x, y = map(
            int,
            input(
                'Please input the coordinates as "x y" to place, starting from 1: '
            ).split(),
        )
        return x - 1, y - 1

    def set_winner(self):
        """
        Display winner information.
        """
        print("Congratulation, you win!")

    def set_loser(self):
        """
        Display loser information.
        """
        print("Sorry, you lose!")

    def set_tie(self):
        """
        Display tie information.
        """
        print("Tie!")

    def clean(self):
        """
        clear screen.
        """
        if sys.platform == "win32":
            os.system("cls")
        else:
            os.system("clear")
