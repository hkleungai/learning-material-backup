import turtle

# Change the turtle shape
turtle.shape("turtle")
turtle.shapesize(5, 5)

# Turn off animation
turtle.tracer(False)

# An event handling function for the turtle screen click event
def jump(x, y):
    turtle.up()
    turtle.goto(x, y)
    turtle.down()

    turtle.update()

# Assign the event handling function to the turtle window
turtle.onscreenclick(jump)

turtle.done()
