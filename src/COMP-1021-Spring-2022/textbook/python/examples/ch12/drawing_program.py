import turtle

# Change the turtle shape
turtle.shape("circle")
turtle.shapesize(2, 2)

# Disable the animation
turtle.tracer(False)

# Move the turtle when dragged
def move(x, y):
    turtle.goto(x, y)  # Move and draw
    turtle.update()

# Assign the event handling function to the turtle
turtle.ondrag(move)

# Make the turtle 'jump' to the mouse location
def jump(x, y):
    turtle.up()
    turtle.goto(x, y)  # Move without drawing
    turtle.down()
    turtle.update()

# Assign the event handling function to the turtle screen
turtle.onscreenclick(jump)

turtle.done()
