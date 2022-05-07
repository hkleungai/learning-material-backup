# This example creates a new turtle.
# This is in addition to the default turtle.
# However, the default turtle is hidden so it 
# cannot be seen.

import turtle

turtle.hideturtle()

t=turtle.Turtle()
t.shapesize(4, 4)
t.left(180)
t.forward(100)

turtle.done() # Must have this at the end

