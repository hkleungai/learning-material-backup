import turtle

# Disable animation and lift the pen up
turtle.tracer(False)
turtle.up()

# Draw twelve ticks around the stop watch
turtle.forward(200)
turtle.left(90)
for _ in range(12):
    turtle.circle(200, 30)
    turtle.dot(10)

# Put the turtle at the top of the stop watch
turtle.circle(200, 90)
turtle.shape("circle")
turtle.update()

# Move the turtle to the next second position
def move_one_second():
    turtle.circle(200, -6) # Move the turtle in clockwise direction
    turtle.update()

    # Move the turtle again one second later
    turtle.ontimer(move_one_second, 1000)

# Move the turtle one second after starting the program
turtle.ontimer(move_one_second, 1000)

turtle.done()
