"""
This program is an example of turtle ondrag event
and onscreenclick event handling.

When you click and drag the
turtle, you can make a drawing.

When you click on the screen, the turtle will jump
to the position that you clicked without drawing
a line to that position.
"""

import turtle

# This function runs when you click on the screen
def jump(x, y):
    turtle.up()
    turtle.goto(x, y)
    turtle.down()

# Set the shape of the turtle to circles
turtle.shape("circle")

# The first parameter is the x-stretch factor for the turtle size,
# the second parameter is the y-stretch factor for the turtle size.
# The third parameter sets the border of the turtle to 3 pixels
turtle.shapesize(1, 1, 3)

# Change the pen color to blue
turtle.pencolor("blue")

# Fill the turtle with no colour
turtle.fillcolor("") 

# Change the pen size to 3
turtle.pensize(3)

# Set up the function goto as the turtle mouse drag 
# event handler. After this line of code, whenever 
# the user drags the mouse, the turtle will go to 
# the position it is dragged to.
turtle.ondrag(turtle.goto)

# Set up the function jump as the 
# screen mouse click event handler
turtle.onscreenclick(jump)
# We could use turtle.goto for the above 
# event handler - but then the turtle 
# would draw a line to the new position,
# which is not what we want

# The default turtle speed cannot follow the 
# speed that the user drags the turtle, so we have 
# to increase the turtle speed. We maximize 
# the turtle speed by using turtle.speed(0)
turtle.speed(0)

turtle.done()
