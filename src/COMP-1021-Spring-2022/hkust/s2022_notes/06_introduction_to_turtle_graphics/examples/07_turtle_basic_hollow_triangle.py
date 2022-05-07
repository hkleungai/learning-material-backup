# An example of a turtle drawing a hollow triangle.

import turtle

turtle.width(5)

# Set the starting position of the turtle
turtle.up()

# Position the turtle at a particular (x, y) position on the left side
turtle.goto(-250, 220)
turtle.down()

# Draw a hollow triangle
turtle.forward(500)
turtle.right(120)
turtle.forward(500)
turtle.right(120)
turtle.forward(500)

turtle.done()
