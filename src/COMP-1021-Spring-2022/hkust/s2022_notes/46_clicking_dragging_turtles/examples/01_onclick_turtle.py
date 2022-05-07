"""
This program is an example of turtle onclick event
handling. When you click on the turtle, the turtle 
will draw a circle.

The function 'drawcircle' runs when you click on 
the turtle.
"""

import turtle

# This function runs when you click on the turtle
def drawcircle(x, y):
    turtle.up()
    # Move the turtle near the bottom so that we can draw a  
    # larger circle without the circle going outside the screen
    turtle.goto(0, -180)
    turtle.down()
    turtle.circle(250)

# Enlarge the turtle size
turtle.shapesize(3, 3)      # Set the width and height of the turtle

# Assign the function drawcircle to the turtle mouse click event
turtle.onclick(drawcircle)

turtle.done() # The turtle system has finished

