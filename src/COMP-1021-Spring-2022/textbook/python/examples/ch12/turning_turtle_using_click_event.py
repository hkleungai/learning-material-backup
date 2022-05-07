import turtle

# Make a big turtle shape
turtle.shape("turtle")
turtle.shapesize(5, 5)

# An event handling function for the turtle click event
def turn_left(x, y):
    # Simply turn the turtle to the left
    turtle.left(90)

# Assign the event handling function to the turtle
turtle.onclick(turn_left)

turtle.done()
