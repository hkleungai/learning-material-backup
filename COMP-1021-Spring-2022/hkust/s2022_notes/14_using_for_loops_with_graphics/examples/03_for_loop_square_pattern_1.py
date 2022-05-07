"""
In this example we use a for loop to draw a lot of 'squares'.
These squares are slightly modified each time the for loop is run so that
an interesting pattern is formed.
"""

import turtle

turtle.width(2)     # Set the width to 2 pixels
turtle.color("red") # Set the line colour
turtle.speed(0)     # Draw faster

for i in range(0, 500, 5): # Run 100 times [0, 5, 10, ... 495]
    turtle.forward(i)   # Move the turtle according to the item variable
    turtle.right(91)    # Turn 1 degree more than the right angle

turtle.done()
