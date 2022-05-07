import turtle

# Make a function for drawing a square
def draw_square():
    for _ in range(4):
        turtle.forward(100)
        turtle.left(90)

# Use the function to draw a square
draw_square()

turtle.done()
