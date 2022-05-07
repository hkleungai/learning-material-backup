import turtle

# Change the turtle shape
turtle.shape("circle")
turtle.shapesize(2, 2)

# Disable the animation
turtle.tracer(False)

# Move the turtle when dragged
def move(x, y):
    turtle.goto(x, y)
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

# Assign the event handling function for red
def red():
    turtle.color("red")
    turtle.update()
turtle.onkeypress(red, "r")

# Assign the event handling function for green
def green():
    turtle.color("green")
    turtle.update()
turtle.onkeypress(green, "g")

# Assign the event handling function for blue
def blue():
    turtle.color("blue")
    turtle.update()
turtle.onkeypress(blue, "b")

# Assign the event handling function for black
def black():
    turtle.color("black")
    turtle.update()
turtle.onkeypress(black, "k")

# Assign the event handling function for clearing the window
turtle.onkeypress(turtle.clear, "c")

# Tell turtle to use key events
turtle.listen()

turtle.done()
