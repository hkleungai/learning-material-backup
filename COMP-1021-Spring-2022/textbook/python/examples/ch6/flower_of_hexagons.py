import turtle

for _ in range(10):  # This loop draws 10 petals of the flower
    for _ in range(6):  # Each petal is a single hexagon
        turtle.forward(100)
        turtle.right(60)
    turtle.right(36)

turtle.done()
