"""
This example shows how to change the turtle shapes in the turtle module. The
default available shapes are used as well as a custom shape created by a GIF
image file.
"""

import turtle

# Clear the screen and draw a square
def draw():
    turtle.clear()
    for _ in range(4):
        turtle.forward(100)
        turtle.left(90)

# Change the turtle shape to 'arrow'
def arrow_shape():
    turtle.shape("arrow")
    draw()

# Change the turtle shape to 'circle'
def circle_shape():
    turtle.shape("circle")
    draw()

# Change the turtle shape to 'triangle'
def triangle_shape():
    turtle.shape("triangle")
    draw()

# Change the turtle shape to 'turtle'
def turtle_shape():
    turtle.shape("turtle")
    draw()

# Change the turtle shape to 'square'
def square_shape():
    turtle.shape("square")
    draw()

# Change the turtle shape to 'classic'
def classic_shape():
    turtle.shape("classic")
    draw()

# Change the turtle shape to a GIF image
def gif_shape():
    turtle.addshape("ninja.gif")
    turtle.shape("ninja.gif")
    draw()

# Start of the main program
print("Repeatedly press Enter to see a new shape")

arrow_shape()
input("Press Enter")

circle_shape()
input("Press Enter")

triangle_shape()
input("Press Enter")

turtle_shape()
input("Press Enter")

square_shape()
input("Press Enter")

classic_shape()
input("Press Enter")

gif_shape()
input("Press Enter")

turtle.done()

# End of the program
