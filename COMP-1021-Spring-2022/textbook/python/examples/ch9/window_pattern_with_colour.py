import turtle

# Make a function for drawing a square
# of a certain colour and size
def draw_square(colour, size):
    turtle.fillcolor(colour)

    turtle.begin_fill()
    for _ in range(4):
        turtle.forward(size)
        turtle.left(90)
    turtle.end_fill()

# Draw a 'window' using five squares
turtle.up()
turtle.goto(-130, -130)
turtle.down()
draw_square("lightyellow", 260)  # The outer square

turtle.up()
turtle.goto(-110, 10)
turtle.down()
draw_square("skyblue", 100)  # The top left square

turtle.up()
turtle.goto(10, 10)
turtle.down()
draw_square("skyblue", 100)  # The top right square

turtle.up()
turtle.goto(-110, -110)
turtle.down()
draw_square("skyblue", 100)  # The bottom left square

turtle.up()
turtle.goto(10, -110)
turtle.down()
draw_square("skyblue", 100)  # The bottom right square

turtle.done()
