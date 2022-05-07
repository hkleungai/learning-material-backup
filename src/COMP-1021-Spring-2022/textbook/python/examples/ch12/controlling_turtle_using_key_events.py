import turtle

# Change the turtle shape
turtle.shape("turtle")
turtle.shapesize(2, 2)

# Disable the animation
turtle.tracer(False)

# Move the turtle forward when the up key is pressed
def move_forward():
    turtle.forward(50)  # The turtle moves 50 pixels each time
    turtle.update()

# Turn the turtle when the left key is pressed
def turn_left():
    turtle.left(90)  # The turtle turns left 90 degrees
    turtle.update()

# Turn the turtle when the right key is pressed
def turn_right():
    turtle.right(90)  # The turtle turns right 90 degrees
    turtle.update()

# Put the pen up when the U key is pressed
def pen_up():
    turtle.up()
    turtle.update()

# Put the pen down when the D key is pressed
def pen_down():
    turtle.down()
    turtle.update()

# Clear the turtle window when the C key is pressed
def clear_window():
    # Move the turtle back to home and put down the pen
    turtle.home()
    turtle.down()

    turtle.clear()
    turtle.update()

# Assign the key press events
turtle.onkeypress(move_forward, "Up")
turtle.onkeypress(turn_left, "Left")
turtle.onkeypress(turn_right, "Right")
turtle.onkeypress(pen_up, "u")
turtle.onkeypress(pen_down, "d")
turtle.onkeypress(clear_window, "c")

# Ask the turtle to listen to keys
turtle.listen()

turtle.done()
