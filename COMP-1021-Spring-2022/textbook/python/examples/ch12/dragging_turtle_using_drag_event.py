import turtle

# Make a big circle turtle
turtle.shape("circle")
turtle.shapesize(2, 2)

# An event handling function for the turtle drag event
def move(x, y):
    # Move the turtle to the mouse position
    turtle.goto(x, y)

# Assign the event handling function to the turtle
turtle.ondrag(move)

turtle.done()
