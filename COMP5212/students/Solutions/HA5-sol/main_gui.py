# -*- coding: utf-8 -*-
__doc__ = r""" TicTacToe in GUI

This is a script for loading computer agent, and playing tic-tac-toe with human user.
By default, it load the random agent, which chooses a legal random move, hence, easy to defeat.
After you have finished you MLPlayer agent, you can use `python main_gui.py -a MLPlayer` to test your agent.
"""

import sys
from PyQt5.QtWidgets import (
    QApplication,
    QWidget,
    QPushButton,
    QVBoxLayout,
    QGridLayout,
    QLabel,
    QMessageBox,
)
from PyQt5.QtGui import QFont
from PyQt5.QtCore import pyqtSignal, QMutex, QThread, QObject, QWaitCondition
import player
from ui import TicTacToeUI
from tictactoe import TicTacToe
import argparse


class TicTacToeGUI(QWidget, TicTacToeUI):
    __doc__ = r"""
    A UI in Graphic environment.

    * :attr:`mark` keeps the role of player, can either be 1 (for the first player),
      or -1 (for the second).

    * :attr:`board_size` the size of the game board, in tuple of (int, int).

    * :attr:`mark_map` a dict map 1, -1, 0 to corresponding mark. X for 1, O for -1, empty for 0.

    * :attr:`button_grid` a button grid mapped to the board.

    Args:
        mark (int): the role of player, can either be 1 (for the first player),
        or -1 (for the second).

        board_size (tuple of (int, int)): the size of the game board, default to be (3, 3).
    """
    game_end = pyqtSignal(str)
    closed = pyqtSignal() #windows close signal

    def __init__(self, mark, board_size=(3, 3)):
        super(TicTacToeGUI, self).__init__(mark=mark, board_size=board_size)
        self.mark_map = {1: "X", -1: "O", 0: " "}
        self.create_grid(*board_size)
        self.action_lock = QMutex()
        self.moved = QWaitCondition()
        self.next_move = None
        self.game_end.connect(self.game_end_msg)

    def render(self, obs):
        assert obs.shape == self.board_size, "Size does not match!"
        self.update_grid(obs)

    def closeEvent(self, event):
        """
        close event handler, telling starter this window has been closed.
        """
        self.closed.emit()
        event.accept()

    def create_grid(self, h, w):
        """
        create a button grid of size (h, w).
        """
        grid = QGridLayout()
        self.button_grid = [[QPushButton() for j in range(h)] for i in range(w)]
        for i in range(h):
            for j in range(w):
                button_size = 100
                button = self.button_grid[i][j]
                button.setFixedSize(button_size, button_size)
                button.setFont(QFont("consolas", 50))
                button.setStyleSheet("border: 0px; color: white; background: gray")
                button.clicked.connect(self.get_place_act(i, j))
                grid.addWidget(self.button_grid[i][j], i + 1, j + 1)
        self.setLayout(grid)

    def update_grid(self, obs):
        """
        synchronize button_grid with obs.
        """
        for i, row in enumerate(self.button_grid):
            for j, button in enumerate(row):
                button.setDisabled(obs[i][j] != 0)
                button.setText(self.mark_map[obs[i][j]])

    def get_action(self):
        """
        wait for user's input and return the action.
        """
        self.action_lock.lock()
        self.next_move = None
        self.moved.wait(self.action_lock)
        self.action_lock.unlock()
        assert isinstance(self.next_move, tuple)
        return self.next_move

    def get_place_act(self, i, j):
        """
        return a function to handle button click event at (i, j).
        """
        def place():
            self.action_lock.lock()
            self.next_move = (i, j)
            self.moved.wakeAll()
            self.action_lock.unlock()

        return place

    def game_end_msg(self, msg):
        msg_box = QMessageBox(self)
        msg_box.setWindowTitle("Game End")
        msg_box.setText(msg)
        msg_box.exec()
        self.close()

    def set_winner(self):
        self.game_end.emit("Congratulation, you are winner!")

    def set_loser(self):
        self.game_end.emit("Sorry, you lose!")

    def set_tie(self):
        self.game_end.emit("Tie!")


class TicTacToeQt(QObject, TicTacToe):
    __doc__ = r"""
    A worker class for handling the game envrionment and oppoent in another thread,
    to prevent GUI frozen in GUI tasks.
    """
    finished = pyqtSignal()

    def __init__(self, player1, player2):
        super(TicTacToeQt, self).__init__(player1=player1, player2=player2)

    def run(self):
        super(TicTacToeQt, self).run()
        self.finished.emit()


class TicTacToeStarter(QWidget):
    def __init__(self, agent):
        super(TicTacToeStarter, self).__init__()
        self.agent_class = agent

        self.setFixedSize(270, 250)
        self.setWindowTitle("TicTacToe")
        layout = QVBoxLayout()
        self.label = QLabel("Please select a player to start")
        self.label.setFixedHeight(100)
        self.label.setWordWrap(True)
        self.label.setFont(QFont("Arial", 19))
        button_height = 40
        button_font = QFont("consolars", 16)
        self.p1_button = QPushButton("X: Player 1")
        self.p1_button.setFixedHeight(button_height)
        self.p1_button.setFont(button_font)
        self.p2_button = QPushButton("O: Player 2")
        self.p2_button.setFixedHeight(button_height)
        self.p2_button.setFont(button_font)

        layout.addWidget(self.label)
        layout.addWidget(self.p1_button)
        layout.addWidget(self.p2_button)
        self.setLayout(layout)
        self.p1_button.clicked.connect(self.pressP1)
        self.p2_button.clicked.connect(self.pressP2)

    def set_running(self):
        self.p1_button.setDisabled(True)
        self.p2_button.setDisabled(True)
        self.label.setText("Enjoy your game!")

    def reset(self):
        self.p1_button.setDisabled(False)
        self.p2_button.setDisabled(False)
        self.label.setText("Please select a player to start")
        if hasattr(self, "game"):
            self.game.deleteLater()
        if hasattr(self, "bg_thread"):
            self.bg_thread.quit()
            self.bg_thread.wait()
            self.bg_thread.deleteLater()

    def pressP1(self):
        """
        Handling case of user as the first player
        """
        ui = TicTacToeGUI(1)
        ui.show()
        ui.closed.connect(self.reset)

        p1 = player.HumanPlayer(mark=1, ui=ui)
        p2 = self.agent_class(mark=-1)
        self.game = TicTacToeQt(p1, p2)
        self.run()

    def pressP2(self):
        """
        Handling case of user as the second player
        """
        ui = TicTacToeGUI(-1)
        ui.show()
        ui.closed.connect(self.reset)

        p1 = self.agent_class(mark=1)
        p2 = player.HumanPlayer(mark=-1, ui=ui)
        self.game = TicTacToeQt(p1, p2)
        self.run()

    def run(self):
        self.set_running()
        self.bg_thread = QThread()
        self.game.moveToThread(self.bg_thread)
        self.bg_thread.started.connect(self.game.run)
        self.bg_thread.start()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="A Tic-TacToe game in GUI")
    parser.add_argument(
        "-a",
        "--agent",
        choices=["RandomPlayer", "MLPlayer"],
        default="RandomPlayer",
        help="The agent class of the computer player",
    )

    args = parser.parse_args()
    Agent = getattr(player, args.agent)

    # creating a starter of tictactoe
    app = QApplication(sys.argv)
    w = TicTacToeStarter(agent=Agent)
    w.show()
    sys.exit(app.exec_())
