"""
This example uses keys to control
the movement of the turtle:
    Up key - move forward
    Down key - move backward
    Left key - rotate left
    Right key - rotate right

It also allow color change:
    'o' key - orange
    'p' key - purple
    'c' key - cyan
"""
import turtle

# Declare some variables we will use in some event handlers
pixels_for_one_step = 4
angle_for_rotation = 5


# These are event handlers for turtle movement

def moveforward():
    # This event handler function moves
    # the turtle forward (up arrow key)
    turtle.forward(pixels_for_one_step)

def movebackward():
    # This event handler function moves
    # the turtle backward (down arrow key)
    turtle.backward(pixels_for_one_step)

def rotateleft():
    # This event handler function rotates
    # the turtle to the left (left arrow key)
    turtle.left(angle_for_rotation)

def rotateright():
    # This event handler function rotates
    # the turtle to the right (right arrow key)
    turtle.right(angle_for_rotation)


# These are event handlers for changing color

def orange(): # For the 'o' key
    # Change the pen color and
    # the turtle to orange
    turtle.color("orange")

def purple(): # For the 'p' key
    # Change the pen color and
    # the turtle to purple
    turtle.color("purple")

def cyan(): # For the 'c' key
    # Change the pen color and
    # the turtle to cyan
    turtle.color("cyan")


# This is the main part of the program

# Reset the turtle
turtle.shape("turtle")
turtle.speed(0)
turtle.color("purple")
turtle.width(3)

# Assign the up, down, left and right keys
# for moving the turtle
turtle.onkeypress(moveforward, "Up")
turtle.onkeypress(movebackward, "Down")
turtle.onkeypress(rotateleft, "Left")
turtle.onkeypress(rotateright, "Right")

# Assign the 'o', 'p', and 'c' keys
# for the color change functions
turtle.onkeypress(orange, "o")
turtle.onkeypress(purple, "p")
turtle.onkeypress(cyan, "c")

# Make sure keyboard events go to this window
turtle.listen()

# Wait for any events and handle them
turtle.done()
