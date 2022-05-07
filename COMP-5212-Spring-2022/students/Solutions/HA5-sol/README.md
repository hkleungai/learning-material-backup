# Hand-in Assignment 5

**Due date**: *see the website*

Use Q-Learning to create a program that can play Tic-Tac-Toe with a human player.


The basic code for Tic-Tac-Toe is given. **What you need to do is to finish the missing part of MLPlayer in the *player.py* file, following the documentations and comments given.** Your implementation should be able to directly replace the *RandomPlayer* in the two main scripts, and good enough to win human player (if a human player makes mistake) or draw every time.

## Usage

To run the game with a random agent, which chooses a random available position, and put mark there. run

```shell
python main.py
```

for a terminal interface. or run

```shell
python main_gui.py
```

for a graphic interface. You will need the PyQt5 library to support it. To install it, run

```shell
pip install PyQt5
```



**After you have finished your agent**, you can run

```shell
python main.py -a MLPlayer
```

or

```shell
python main_gui.py -a MLPlayer
```

to test your agent manually.



**Note**: the given training script is just an example, you can change it arbitrary as long as your MLPlayer can be directly and correctly loaded in these game scripts.



## Submission

Please submit your *player.py* file together with your saved table file in a zip file in canvas submission page. **Finish it by yourself, there is no tolerance for plagiarism.**