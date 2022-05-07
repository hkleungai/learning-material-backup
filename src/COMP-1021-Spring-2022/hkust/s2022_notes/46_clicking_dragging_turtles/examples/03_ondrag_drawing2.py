"""
This program is an example of turtle ondrag event
handling. When you drag the turtle, you can make a drawing.
"""

import turtle

# Set the shape of the turtle to a circle
turtle.shape("circle")

# Change the color to blue
turtle.color("blue")

# Change the pen size to 3 so it looks stronger
turtle.pensize(3)

# Assign the function goto to the turtle mouse drag 
# event handler. After this line of code, whenever 
# the user drags the mouse, the turtle will go to 
# the position it is dragged to.
turtle.ondrag(turtle.goto)

# The default turtle speed cannot follow the 
# speed that the user drags the turtle, so we have 
# to increase the turtle speed. For convenience, 
# we maximize the turtle speed by using turtle.speed(0)
turtle.speed(0)

turtle.done() # The turtle system has finished

