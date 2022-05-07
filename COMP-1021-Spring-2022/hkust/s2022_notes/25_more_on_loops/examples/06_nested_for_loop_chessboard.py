"""
This example draws a chess board using nested for loops and
the continue command.
"""

import turtle

turtle.speed(0)     # Use the fastest speed

# Move to the top left corner of the chess board 
turtle.up()
turtle.goto(-200, 200)
turtle.down()

# Draw the boxes using gray colour
turtle.color("", "gray")

# Outer loop for chess board rows
for row in range(8):

    # Inner loop for chess board columns
    for col in range(8):
        # Skip the white boxes depending on
        # the combination of row and column
        if col % 2 == row % 2:
            # Move to the next column
            turtle.forward(50)
            continue

        # Draw a gray box
        turtle.begin_fill()
        for _ in range(4):
            turtle.forward(50)
            turtle.right(90)
        turtle.end_fill()

        # Move to the next box area 
        turtle.forward(50)

    # Move to the next row
    turtle.backward(400)
    turtle.right(90)
    turtle.forward(50)
    turtle.left(90)

# Draw the border of the board
turtle.up()
turtle.goto(-200, 200)
turtle.down()
turtle.color("black")
turtle.width(2)
for _ in range(4):
    turtle.forward(400)
    turtle.right(90)

# Draw a queen
turtle.up()
turtle.goto(-50, -200)
turtle.forward(15)
turtle.left(90)
turtle.forward(7)
turtle.down()
turtle.left(15)
turtle.forward(25)
turtle.dot(7)
turtle.right(155)
turtle.forward(15)
turtle.left(140)
turtle.forward(20)
turtle.dot(7)
turtle.right(160)
turtle.forward(20)
turtle.left(140)
turtle.forward(20)
turtle.dot(7)
turtle.right(160)
turtle.forward(20)
turtle.left(140)
turtle.forward(15)
turtle.dot(7)
turtle.right(155)
turtle.forward(25)
turtle.right(75)
turtle.forward(20)

# Move the turtle to the corner of the chess board so that it does not stay
# on top of the king when the drawing is finished
turtle.up()
turtle.goto(-200, -200)
turtle.down()

turtle.done()
