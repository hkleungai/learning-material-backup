"""
    In this example, a function is defined which is then used
    by two other functions.
"""

import turtle

def forward_and_turn_right(length, angle):
    # Walk forward "length" pixels and then turn right "angle" degrees.
    turtle.forward(length)
    turtle.right(angle)


def draw_square(length, line_colour, fill_colour):
    # Draw a square.
    turtle.color(line_colour, fill_colour)
    turtle.begin_fill()
    for _ in range(4):
        forward_and_turn_right(length, 90)
    turtle.end_fill()


def draw_star(length, line_colour, fill_colour):
    # Draw a star.
    turtle.color(line_colour, fill_colour)
    turtle.begin_fill()
    for _ in range(5):
        forward_and_turn_right(length, 144)
    turtle.end_fill()


# Prepare the turtle
turtle.width(5)

# Draw a blue square with a yellow border with side 200 pixels
draw_square(200, "yellow", "blue")

turtle.right(180)

# Draw a yellow star with a blue border with side 300 pixels
draw_star(300, "blue", "yellow")

turtle.done()
