# -*- coding: utf-8 -*-
__doc__ = r""" TicTacToe in TUI

This is a script for loading computer agent, and playing tic-tac-toe with human user.
By default, it load the random agent, which chooses a legal random move, hence, easy to defeat.
After you have finished you MLPlayer agent, you can use `python main.py -a MLPlayer` to test your agent.
"""

import numpy as np
from tictactoe import TicTacToe
import argparse
import player

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="A Tic-TacToe game rendered in Terminal")
    parser.add_argument("-a", "--agent", choices=["RandomPlayer", "MLPlayer"], default="RandomPlayer", help="The agent class of the computer player")

    args = parser.parse_args()
    Agent = getattr(player, args.agent)
    
    pvc = player.HumanPlayer(mark=1), Agent(mark=-1) #Player vs Computer pair
    cvp = Agent(mark=1), player.HumanPlayer(mark=-1) #Computer vs Player pair

    play = True
    while play:
        order = input("First player or second? [1/2]: ").strip()
        assert order in ["1", "2"], "Invalid selection!"
        pair = pvc if order == "1" else cvp

        game = TicTacToe(*pair)
        game.run()

        play = input("Play again:[Y/n]").lower() != "n"
