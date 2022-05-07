import turtle

# Make a big circle turtle
turtle.shape("circle")
turtle.shapesize(2, 2)

# Assign turtle.goto directly as an event handling function
turtle.ondrag(turtle.goto)

turtle.done()
