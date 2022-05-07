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

# Save the current key sequence to a text file
def save_data():
    keys_file = open("keys.txt", "w")

    # Put each key on a separate line of the file
    for key in keys:
        keys_file.write(key + "\n")
        
    keys_file.close() 

# Assign the S key for saving data
turtle.onkeypress(save_data, "s")

# Load the key sequence from a text file
def load_data():
    # Clear the window before loading a picture
    clear_window()
    
    keys_file = open("keys.txt", "r")

    # Read each line, i.e. key, from the file
    for key in keys_file:
        key = key.rstrip()  # Remove the ending newline

        # Run the corresponding function for each key
        if key == "Up":
            move_forward()
        elif key == "Left":
            turn_left()
        elif key == "Right":
            turn_right()
        elif key == "u":
            pen_up()
        elif key == "d":
            pen_down()
        
    keys_file.close()
    
# Assign the L key for loading data
turtle.onkeypress(load_data, "l")

turtle.listen()

turtle.done()
