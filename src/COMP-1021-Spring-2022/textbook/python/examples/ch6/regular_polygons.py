import turtle

# Get the number of sides from the user
number_of_sides = int(input("How many sides do you want? "))

side = 0  # Initialise side to 0

while side < number_of_sides:  # Repeat until all sides are drawn
    turtle.forward(100)

    # This is the angle to turn for a regular polygon
    turtle.left(360 / number_of_sides)

    side = side + 1  # Increase the number of side drawn by the loop
    
turtle.done()
