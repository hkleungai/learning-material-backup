# An example which uses left() and right()

import turtle

# Make it thicker simply for better visibility
turtle.width(5)

# Tell the turtle to turn left 5 degrees
turtle.left(5)

# Draw the right box and the connecting line
turtle.forward(175)
turtle.left(90)
turtle.forward(100)
turtle.left(90)
turtle.forward(100)
turtle.left(90)
turtle.forward(100)

turtle.right(90)

# Draw the left box and the connecting line
turtle.forward(225)
turtle.right(90)
turtle.forward(75)
turtle.right(90)
turtle.forward(75)
turtle.right(90)
turtle.forward(75)

# Return to the centre
turtle.left(90)
turtle.forward(75)
turtle.right(95)

# Draw the base
turtle.forward(25)
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
