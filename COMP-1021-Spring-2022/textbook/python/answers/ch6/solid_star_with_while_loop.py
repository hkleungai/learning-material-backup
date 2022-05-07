import turtle

turtle.color("", "yellow")

turtle.begin_fill()

side = 0
while side < 5:
    turtle.forward(150)
    turtle.right(144)
    side = side + 1

turtle.end_fill()

turtle.done()
