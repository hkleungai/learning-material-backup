import turtle

# Start to draw from the left hand side of the window
turtle.up()
turtle.backward(125)

number_of_dots = 25  # The bottom row has 25 dots

while number_of_dots > 0:  # Draw until there are no more dots in a row

    # This is the inner loop to draw each row of dots
    dots_drawn = 0
    while dots_drawn < number_of_dots:
        turtle.dot(10)
        turtle.forward(10)
        
        dots_drawn = dots_drawn + 1

    # Move to the starting position of the next row
    turtle.backward(number_of_dots * 10)
    turtle.left(90)
    turtle.forward(10)
    turtle.right(90)
    turtle.forward(10)
    
    # The number of dots is decreased by 2 each time
    number_of_dots = number_of_dots - 2

turtle.hideturtle()

turtle.done()
