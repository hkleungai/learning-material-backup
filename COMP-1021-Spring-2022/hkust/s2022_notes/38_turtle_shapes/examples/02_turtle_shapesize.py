"""
This example changes the shape size of the turtle shape according to the
user input.
"""

import turtle

# Change the turtle shape to a turtle and use red colour
turtle.shape("turtle")
turtle.color("red")

# Get the user input for the width and length of the turtle shape
width = input("Enter the width of the shape: ")
length = input("Enter the length of the shape: ")

# Change the size according to the input values
turtle.shapesize(float(width), float(length))

turtle.done()
