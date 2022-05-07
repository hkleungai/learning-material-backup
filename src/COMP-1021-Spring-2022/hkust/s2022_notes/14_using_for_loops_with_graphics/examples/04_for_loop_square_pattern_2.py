"""
In this example two for loops are used to draw a kind of spiral structure.
"""

import turtle

turtle.width(2)     # Set the width to 2 pixels
turtle.color("purple") # Set the line colour
turtle.speed(0)     # Draw faster

for i in range(0, 400, 2):
    turtle.forward(i)   # Move the turtle according to the item variable
    turtle.right(89)    # Turn 1 degree less than the right angle

for i in range(401, 0, -2):
    turtle.forward(i)   # Move the turtle according to the item variable
    turtle.right(89)    # Turn 1 degree less than the right angle

turtle.done()
