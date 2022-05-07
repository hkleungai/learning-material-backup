import turtle

# This function makes a big turtle as the turtle shape
def make_big_turtle():
    turtle.shape("turtle")
    turtle.shapesize(4, 4)

# Arrange the timer event to occur after 2 seconds
turtle.ontimer(make_big_turtle, 2000)

# Change the turtle to the arrow shape
turtle.shape("arrow")

turtle.done()
