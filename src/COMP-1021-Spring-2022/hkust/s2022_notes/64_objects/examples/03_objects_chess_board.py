"""
In this example we have improved the earlier SimpleSquare class. This class
represents a square. The class has four attributes, the x and y position of
the bottom left corner, the length of one side, and the colour of the square,
which is filled. When an instance of the class is created it must be given
the initial values of the four attributes. 
        
In this example we make a chess board pattern. Each square in the chess board 
is an instance of the class. Each instance has a unique position.
"""

import turtle
        
class ImprovedSquare:
    # This is the constructor of the object
    def __init__(self, x, y, length, color):
        # Initialize the attributes of the square
        self.x = x
        self.y = y
        self.length = length
        self.color = color
        
    # This method returns the area of the square
    def area(self):
        return self.length * self.length

    # This method draws the square itself using turtle
    def draw(self):
        turtle.up()
        turtle.goto(self.x, self.y)
        turtle.down()
        turtle.fillcolor(self.color)
        turtle.begin_fill()
        for _ in range(4):
            turtle.forward(self.length)
            turtle.left(90)
        turtle.end_fill()

# This is the main part of the program
turtle.setup(500, 500)
turtle.hideturtle()     # No need to see the turtle
turtle.tracer(False)    # Don't want to see the movement

side = 50               # Length of one side of each square
allsquares = []         # We will add the instances to this list

# Go through each square in the chessboard pattern and generate an appropriate
# instance of the square class
for row in range(8):
    for column in range(8):
        if row % 2 == column % 2:
            thiscolor = "white"
        else:
            thiscolor = "black"

        # Calculate the position of the square
        x = row * side - 4 * side
        y = column * side - 4 * side

        # Now we will make an instance of the class
        square = ImprovedSquare(x, y, side, thiscolor)

        # And add the square to the list
        allsquares.append(square)

# Now, draw all squares from the list
for square in allsquares:
        # We tell the instance to draw itself
        square.draw()

turtle.tracer(True)
turtle.done()
