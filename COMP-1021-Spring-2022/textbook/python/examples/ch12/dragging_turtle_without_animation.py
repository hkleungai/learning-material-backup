import turtle

turtle.shape("circle")
turtle.shapesize(2, 2)

# Disable the animation
turtle.tracer(False)

def move(x, y):
    turtle.goto(x, y)
    turtle.update()  # Must use this to show the turtle movement

turtle.ondrag(move)

turtle.done()
