import turtle

# A list to store the key sequence
keys = []

turtle.shape("turtle")
turtle.shapesize(2, 2)

turtle.tracer(False)

# Move the turtle forward when the up key is pressed
def move_forward():
    keys.append("Up")

    turtle.forward(50)  # The turtle moves 50 pixels each time
    turtle.update()

# Turn the turtle when the left key is pressed
def turn_left():
    keys.append("Left")

    turtle.left(90)  # The turtle turns left 90 degrees
    turtle.update()

# Turn the turtle when the right key is pressed
def turn_right():
    keys.append("Right")

    turtle.right(90)  # The turtle turns right 90 degrees
    turtle.update()

# Put the pen up when the U key is pressed
def pen_up():
    keys.append("u")

    turtle.up()
    turtle.update()

# Put the pen down when the D key is pressed
def pen_down():
    keys.append("d")

    turtle.down()
    turtle.update()

# Clear the turtle window when the C key is pressed
def clear_window():
    # Clear the list keys
    global keys
    keys = []

    turtle.home()
    turtle.down()

    turtle.clear()
    turtle.update()

turtle.onkeypress(move_forward, "Up")
turtle.onkeypress(turn_left, "Left")
turtle.onkeypress(turn_right, "Right")
turtle.onkeypress(pen_up, "u")
turtle.onkeypress(pen_down, "d")
turtle.onkeypress(clear_window, "c")

turtle.listen()

turtle.done()
