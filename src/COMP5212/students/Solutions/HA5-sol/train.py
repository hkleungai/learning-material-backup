# -*- coding: utf-8 -*-
__doc__ = """This is a script for training Q-Learning Agent"""

import numpy as np
from tictactoe import TicTacToe
from player import MLPlayer, RandomPlayer
import matplotlib.pyplot as plt
import argparse

def prepare_agent(mark):
    """
    Create and configure MLPlayer agent.

    Args:
        mark (int): either 1 or -1, indicates the mark agent use,
            1 for first player, -1 for the second player.
    
    Returns:
        agent (Player): the configured MLPlayer.
    """
    agent = MLPlayer(mark)
    agent.set_mode("train")
    return agent

if __name__ == "__main__":
    parser = argparse.ArgumentParser("Train Q-Learning agent")
    parser.add_argument("-n", "--num", type=int, required=True, help="The number of games for training")
    args = parser.parse_args()

    p1 = prepare_agent(mark=1)
    p2 = prepare_agent(mark=-1)

    #define the tester
    test_p1 = RandomPlayer(mark=1)
    test_p2 = RandomPlayer(mark=-1)


    game = TicTacToe(p1, p2)
    p1_test_game = TicTacToe(p1, test_p2)
    p2_test_game = TicTacToe(test_p1, p2)

    N = args.num
    hist_p1, hist_p2 = [], []

    for i in range(1, N+1):
        #training part
        p1.set_mode("train")
        p2.set_mode("train")
        game.run()
        if i % 200 == 0:
            #test part
            p1.set_mode("eval")
            p2.set_mode("eval")
            print("game{:9}:".format(i))
            res = [p1_test_game.run() for i in range(100)]

            win_rate = len([r for r in res if r == 1]) / len(res)
            lose_rate = len([r for r in res if r == -1]) / len(res)
            tie_rate = len([r for r in res if r == 0]) / len(res)
            hist_p1.append((win_rate, lose_rate, tie_rate))

            print("    MLPlayer vs RandomPlayer: p1_win: {:4.0%} p2_win: {:4.0%} tie: {:4.0%}".format(win_rate, lose_rate, tie_rate))

            res = [p2_test_game.run() for i in range(100)]

            win_rate = len([r for r in res if r == 1]) / len(res)
            lose_rate = len([r for r in res if r == -1]) / len(res)
            tie_rate = len([r for r in res if r == 0]) / len(res)
            hist_p2.append((lose_rate, win_rate, tie_rate))

            print("    RandomPlayer vs MLPlayer: p1_win: {:4.0%} p2_win: {:4.0%} tie: {:4.0%}".format(win_rate, lose_rate, tie_rate))
            
            res = game.run()
            print("    Self play: {}".format("p1_win" if res == 1 else ("p2_win" if res == -1 else "tie")))
            print()
    p1.save()
    p2.save()
    
    # Plot part
    if len(hist_p1) > 100:
        def running_average(arr, length):
            ker = np.ones(length) / length
            return np.convolve(arr, ker, mode="valid")
        
        def running_max(arr, length):
            arr = [arr[i:i+length] for i in range(len(arr) - length + 1)]
            arr = np.asarray(arr)
            maxs = np.max(arr, -1)
            return maxs

        def running_min(arr, length):
            arr = [arr[i:i+length] for i in range(len(arr) - length + 1)]
            arr = np.asarray(arr)
            mins = np.min(arr, -1)
            return mins

        x = np.arange(len(hist_p1)) + 1
        p1_win_a, p1_lose_a, p1_tie_a = [running_average(x, 100) for x in zip(*hist_p1)]
        p1_win_max, p1_lose_max, p1_tie_max = [running_max(x, 100) for x in zip(*hist_p1)]
        p1_win_min, p1_lose_min, p1_tie_min = [running_min(x, 100) for x in zip(*hist_p1)]

        x = x[: len(p1_win_a)]

        #Plot for MLPlayer as the first player
        plt.figure()
        plt.title("P1 record")
        plt.plot(x, p1_win_a, label="p1_win")
        plt.fill_between(x, p1_win_min, p1_win_max, alpha = 0.5)

        plt.plot(x, p1_lose_a, label="p1_lose")
        plt.fill_between(x, p1_lose_min, p1_lose_max, alpha = 0.5)

        plt.plot(x, p1_tie_a, "--", label="p1_tie")
        plt.fill_between(x, p1_tie_min, p1_tie_max, alpha = 0.5)
        plt.xlim(left=0, right=x[-1])
        plt.ylim(top=1, bottom=0)
        plt.legend()

        p2_win_a, p2_lose_a, p2_tie_a = [running_average(x, 100) for x in zip(*hist_p2)]
        p2_win_max, p2_lose_max, p2_tie_max = [running_max(x, 100) for x in zip(*hist_p2)]
        p2_win_min, p2_lose_min, p2_tie_min = [running_min(x, 100) for x in zip(*hist_p2)]

        #Plot for MLPlayer as the second player
        plt.figure()
        plt.title("P2 record")
        plt.plot(x, p2_win_a, label="p2_win")
        plt.fill_between(x, p2_win_min, p2_win_max, alpha = 0.5)

        plt.plot(x, p2_lose_a, label="p2_lose")
        plt.fill_between(x, p2_lose_min, p2_lose_max, alpha = 0.5)

        plt.plot(x, p2_tie_a, "--", label="p2_tie")
        plt.fill_between(x, p2_tie_min, p2_tie_max, alpha = 0.5)
        plt.xlim(left=0, right=x[-1])
        plt.ylim(top=1, bottom=0)
        plt.legend()
        plt.show()
