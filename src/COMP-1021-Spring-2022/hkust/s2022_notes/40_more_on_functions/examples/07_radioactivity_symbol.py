# In this example a turtle creates the
# warning symbol for radioactivity

import turtle

def square(length):
    # Draw a square of length pixels
    for i in range(4):
        turtle.forward(length)
        turtle.left(90)

def sector(radius, angle):
    # Draw part of a circle
    turtle.forward(radius)
    turtle.left(90)
    turtle.circle(radius, angle)
    turtle.left(90)
    turtle.forward(radius)
    turtle.left(180-angle)

def move(x, y):
    # Move forward and left
    turtle.up()
    turtle.forward(x)
    turtle.left(90)
    turtle.forward(y)
    turtle.right(90)
    turtle.down()

def draw_symbol(large_radius, small_radius, side):
    move(-(side/2), -(side/2))

    turtle.color("black", "yellow")
    # Draw outer yellow square
    turtle.begin_fill()
    turtle.width(5)
    square(side)
    turtle.end_fill()
    
    move(side/2, side/2)
    
    # Draw the complete symbol
    turtle.color("yellow", "black")
    turtle.width(1)

    # Draw three sections
    for i in range(3):
        turtle.begin_fill()
        sector(large_radius, 60)
        turtle.left(120)
        turtle.end_fill()

    turtle.forward(small_radius)
    turtle.left(90)

    # Draw centre circle
    turtle.width(5)
    turtle.begin_fill()
    turtle.circle(small_radius)
    turtle.end_fill()

# Main part of program
draw_symbol(160, 36, 400)
turtle.hideturtle()
turtle.done()
