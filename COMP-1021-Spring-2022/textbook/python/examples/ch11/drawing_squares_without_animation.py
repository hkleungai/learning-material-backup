import turtle

# Turn off the animation
turtle.tracer(False)

# Draw a pattern using 36 squares
for _ in range(36):
    for _ in range(4):
        turtle.forward(100)
        turtle.left(90)
    turtle.left(10)

# Turn on the animation so that the square drawn above is shown
turtle.tracer(True)

turtle.done()
