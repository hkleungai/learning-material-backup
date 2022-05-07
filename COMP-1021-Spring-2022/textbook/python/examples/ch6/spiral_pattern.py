import turtle

for length in range(5, 500, 5):  # Draw lines with different lengths
    turtle.forward(length)
    turtle.right(91)  # Rotate slightly more than the right angle

turtle.done()
