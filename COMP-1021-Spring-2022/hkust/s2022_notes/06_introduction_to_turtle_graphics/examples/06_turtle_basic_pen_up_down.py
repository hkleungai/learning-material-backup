# When the turtle lifts up the pen, nothing is drawn on 
# the "ground" when the turtle moves around.
#
# This example is the same as the previous example, but 
# the pen is taken off the ground at various places.

import turtle

turtle.width(5)

# Tell the turtle to turn left 5 degrees
turtle.left(5)

# Lift up the pen
turtle.up()

# From now on, the turtle will not draw anything when it moves.

# Turtle walks forward but draws nothing.
turtle.forward(75)

# Put down the pen
turtle.down()

# The turtle draws again.

# Draw the right box
turtle.forward(100)
turtle.left(90)
turtle.forward(100)
turtle.left(90)
turtle.forward(100)
turtle.left(90)
turtle.forward(100)

turtle.right(90)

turtle.up()
turtle.forward(150)
turtle.down()

# Draw the left box
turtle.forward(75)
turtle.right(90)
turtle.forward(75)
turtle.right(90)
turtle.forward(75)
turtle.right(90)
turtle.forward(75)

# Return to the centre
turtle.up()
turtle.left(90)
turtle.forward(75)
turtle.right(95)
turtle.forward(25)
turtle.down()

# Draw the base
turtle.left(90)
turtle.forward(50)
turtle.right(90)
turtle.forward(20)
turtle.right(90)
turtle.forward(100)
turtle.right(90)
turtle.forward(20)
turtle.right(90)
turtle.forward(50)

turtle.done()
