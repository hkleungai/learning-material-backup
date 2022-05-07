import turtle

actions = []

# Change the turtle shape
turtle.shape("circle")
turtle.shapesize(2, 2)

# Disable the animation
turtle.tracer(False)

# Move the turtle when dragged
def move(x, y):
    actions.append("Move " + str(x) + " " + str(y))
    turtle.goto(x, y)
    turtle.update()

# Assign the event handling function to the turtle
turtle.ondrag(move)

# Make the turtle 'jump' to the mouse location
def jump(x, y):
    actions.append("Jump " + str(x) + " " + str(y))
    turtle.up()
    turtle.goto(x, y)  # Move without drawing
    turtle.down()
    turtle.update()

# Assign the event handling function to the turtle screen
turtle.onscreenclick(jump)

# Make the key to save the current content to a file
def save():
    # Save each action into the file
    file = open("picture.txt", "w")
    for action in actions:
        file.write(action + "\n")
    file.close()
turtle.onkeypress(save, "s")

# Make the key to load content from a file
def load():
    global actions

    # Clear the current content
    actions = []
    turtle.home()
    turtle.clear()

    # Load each line and perform the corresponding action
    file = open("picture.txt", "r")
    for action in file:
        data = action.rstrip().split(" ")
        if data[0] == "Move":
            move(float(data[1]), float(data[2]))
        elif data[0] == "Jump":
            jump(float(data[1]), float(data[2]))
    file.close()
turtle.onkeypress(load, "l")

turtle.listen()

turtle.done()
