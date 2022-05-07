import turtle

turtle.width(10)  # Draw with a thick pen

# Define the height of the letter 'B'
height = 100

# Draw the bottom part of the 'B' with proportion based on the height
turtle.forward(height / 3)
turtle.circle(height / 4 + height * 0.05, 180)
turtle.forward(height / 3)
turtle.left(180)

# Draw the top part of the 'B' with proportion based on the height
turtle.forward(height / 3)
turtle.circle(height / 4 - height * 0.05, 180)
turtle.forward(height / 3)

# Draw the vertical line of the 'B'
turtle.left(90)
turtle.forward(height)

turtle.done()
