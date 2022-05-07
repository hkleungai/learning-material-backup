"""
This is an example of using nested for loops to draw a pyramid of dots.
"""

import turtle

turtle.color("brown")
turtle.speed(0)
turtle.up()
turtle.hideturtle()

size = 20

turtle.goto(0, 80)

for i in range(0, 15, 2):
    for j in range(i + 1):
        turtle.dot(size)
        turtle.forward(size)

    turtle.backward(size * (i + 2))
    turtle.right(90)
    turtle.forward(size)
    turtle.left(90)
    
turtle.done()
