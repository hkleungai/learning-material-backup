import turtle

turtle.color("red")
turtle.width(10)

side = 0
while side < 4:
    turtle.forward(200)
    turtle.right(90)
    side = side + 1

turtle.done()
