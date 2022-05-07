"""
In this example we have improved the earlier SimpleSquare class. This class
represents a square. The class has four attributes, the x and y position of
the bottom left corner, the length of one side, and the colour of the square,
which is filled. When an instance of the class is created it must be given
the initial values of the four attributes. 
        
In this example we make an instance of the class, and then ask the instance
what area it has. Then we ask the instance to draw itself on the screen.
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

# Create a square and show the area
mysquare = ImprovedSquare(-125, -125, 250, "red")
print( "The area is", mysquare.area())

# Draw the square on the screen
mysquare.draw()

turtle.done()
