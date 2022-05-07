import turtle

side = 0  # Initialise side to 0

while side < 4:  # Repeat while the loop draws less than four sides
    turtle.forward(120)
    turtle.left(90)

    side = side + 1  # Increase the number of side drawn by the loop

turtle.done()
