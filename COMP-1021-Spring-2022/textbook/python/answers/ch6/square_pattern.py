import turtle

for size in range(20, 200, 40):
    for _ in range(4):
        turtle.forward(size)
        turtle.left(90)
    turtle.up()
    turtle.backward(20)
    turtle.right(90)
    turtle.forward(20)
    turtle.left(90)
    turtle.down()

turtle.done()
