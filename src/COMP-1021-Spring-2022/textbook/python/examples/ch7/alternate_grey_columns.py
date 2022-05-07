import turtle

turtle.color("", "gray")  # Draw grey boxes only

turtle.speed(0)
turtle.goto(-200, 200)

for row in range(8):
    for column in range(8):
        if column % 2 == 0:
            # Draw a grey box every two columns
            turtle.begin_fill()
            for _ in range(4):
                turtle.forward(50)
                turtle.right(90)
            turtle.end_fill()

        # Move to the next column
        turtle.forward(50)

    # Move to position of the next row
    turtle.backward(400)
    turtle.right(90)
    turtle.forward(50)
    turtle.left(90)

# Draw the border
turtle.goto(-200, 200)
turtle.width(2)
turtle.color("black")
for _ in range(4):
    turtle.forward(400)
    turtle.right(90)

turtle.done()
