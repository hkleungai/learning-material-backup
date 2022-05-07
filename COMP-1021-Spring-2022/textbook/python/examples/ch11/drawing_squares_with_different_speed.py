import turtle

# Draw a square
def draw_square():
    for _ in range(4):
        turtle.forward(100)
        turtle.left(90)

# Draw a square with the slowest speed
turtle.speed(1)
draw_square()

turtle.clear()  # Clear the turtle window

# Draw a square with the medium speed
turtle.speed(5)
draw_square()

turtle.clear()  # Clear the turtle window

# Draw a square with the fastest possible speed (no animation)
turtle.speed(0)
draw_square()

turtle.done()
