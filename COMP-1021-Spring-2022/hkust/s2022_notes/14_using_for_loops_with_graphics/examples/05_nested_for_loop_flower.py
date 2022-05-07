"""
This is an example of a nested for loop used to create a series of hexagons.
"""

import turtle

turtle.width(5)     # Set the width to 5 pixels
turtle.color("red") # Set the line colour
turtle.speed(10)     # Draw faster

for _ in range(10):
    # Draw a hexagon
    for _ in range(6):
        turtle.forward(120)
        turtle.right(60)
    turtle.right(36)

turtle.done()
