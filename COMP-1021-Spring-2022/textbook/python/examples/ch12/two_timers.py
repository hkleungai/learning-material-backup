import turtle

# This function changes the turtle shape
def make_turtle_shape():
    turtle.shape("turtle")

# This function makes a big turtle
def make_big_turtle():
    turtle.shapesize(4, 4)

# Arrange the first timer event to occur 2 seconds after the start
turtle.ontimer(make_turtle_shape, 2000)

# Arrange the second timer event to occur 4 seconds after the start
turtle.ontimer(make_big_turtle, 4000)

# Change the turtle to the arrow shape
turtle.shape("arrow")

turtle.done()
