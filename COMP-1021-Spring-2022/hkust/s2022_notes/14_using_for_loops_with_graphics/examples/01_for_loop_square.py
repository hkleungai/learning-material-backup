"""
In this example we use a for loop to draw a square.
First, we move the turtle to a position in the upper left of the screen.
Then we use a for loop to move the turtle forward and turn right 90 degrees.
The loop is repeated four times, to make a square.    
"""

import turtle

turtle.width(5)     # Set the width to 5 pixels
turtle.penup()      # Take the pen up (so no lines will be drawn)
turtle.goto(-200, 200)  # Move the turtle to a position in the top left area
turtle.pendown()    # Put the pen down (so now lines will be drawn)

turtle.color("black", "yellow")   # Set the line colour and the fill colour

turtle.begin_fill() # We want this square to be filled

for i in range(4):
    turtle.forward(400) # Move the turtle forward
    turtle.right(90)    # Move the turtle right 90 degrees

turtle.end_fill()   # This triggers the filling of the square

turtle.done()
