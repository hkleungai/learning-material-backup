import turtle

# Make a function for drawing a square
def draw_square():
    for _ in range(4):
        turtle.forward(100)
        turtle.left(90)

# Draw a 'window' using four squares
turtle.up()
turtle.goto(-110, 10)
turtle.down()
draw_square()  # The top left square

turtle.up()
turtle.goto(10, 10)
turtle.down()
draw_square()  # The top right square

turtle.up()
turtle.goto(-110, -110)
turtle.down()
draw_square()  # The bottom left square

turtle.up()
turtle.goto(10, -110)
turtle.down()
draw_square()  # The bottom right square

turtle.done()
