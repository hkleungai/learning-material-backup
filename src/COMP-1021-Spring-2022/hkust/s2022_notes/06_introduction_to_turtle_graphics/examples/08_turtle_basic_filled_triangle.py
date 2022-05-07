# An example of a turtle using a different colour for 
# the fill colour and the line colour.

import turtle

turtle.width(5)

# Set the starting position of the turtle
turtle.up()
turtle.goto(-250, 220)
turtle.down()

# Change the pen colour to red and the fill colour to yellow
turtle.color("red", "yellow")

turtle.begin_fill()

turtle.forward(500)
turtle.right(120)
turtle.forward(500)
turtle.right(120)
turtle.forward(500)

turtle.end_fill()

# We now have a yellow filled triangle with a red border.

turtle.done()
