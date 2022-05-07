# This example draws a pretty flower using a nested loop

# We use four stages to build the flower:
#
# Stage 1: Get the turtle graphics started
# Stage 2: Create the curved stem 
# Stage 3: Draw the petals using a nested loop
# Stage 4: Draw the central yellow part

# -----------------------------------------
# Stage 1: Get the turtle graphics started

# Bring the turtle graphics commands into the Python interpreter
import turtle

# Use a reasonable drawing speed
turtle.speed(0)

# -------------------------------------------------
# Stage 2: Create the curved stem 

# First we draw the curved stem of the flower.
# To draw a curve, we can draw part of a circle.
# Here we draw 30 degrees (a small part) of a very large circle.
turtle.width(20)
turtle.color("green") # "green")

turtle.up()             # Don't draw while we move the turtle
turtle.goto(100, -400)  # Move the turtle near the bottom right
turtle.left(90)         # Point the turtle upwards
turtle.down()           # Start drawing from now onwards
turtle.circle(1000, 30) # Draw small piece of circle with radius 1000

# -------------------------------------------------
# Stage 3: Draw the petals using a nested loop

# Draw the petals using red
turtle.color("red")
turtle.up() # Don't show lines when moving

# The outer while loop uses the inner while loop
# eight times, to draw eight petals in total

starting_distance=40 # Distance away from the center, for first circle
total_petals = 8 # Total number of petals to draw

petal_number = 0 # Start with the first petal
while petal_number < total_petals: # Repeat for 8 petals in total

    # On a real flower petals don't start at the middle,
    # so let's move away from the middle a little
    turtle.forward(starting_distance)
    
    # The following inner loop draws one petal using 13 red circles.
    # Each red circle is drawn further away from the center.
    
    gap_between_circle = 10 # The gap between each circle
    total_circles = 13 # Total number of circles to draw

    circle_number = 0 # Start with the first circle of the petal    
    while circle_number < total_circles: 

        # Calculate the diameter using a clever formula
        diameter = (circle_number + 1) * 1.5 * (total_circles - circle_number)

        # Draw a solid circle
        turtle.dot(diameter)

        # Go to the next circle position
        # (for the following execution of the inner loop)
        turtle.forward(gap_between_circle)

        # Move on to the next circle
        # (for the following execution of the inner loop)
        circle_number = circle_number + 1

    # At this point we have finished drawing all the
    # circles which together make a petal. Now we go back to  
    # the position we started at before we drew this petal.
    turtle.backward(starting_distance + (total_circles * gap_between_circle))

    # Now we get ready for drawing the next petal.
    # First we change the angle of the turtle so
    # it is pointing to the correct direction for the
    # next petal. Each petal is rotated 45 degrees 
    # compared to the previous petal.
    turtle.left(360/ total_petals)

    # Move on to construct the next petal
    # (in the following execution of the outer loop)
    petal_number = petal_number + 1


# At this point we have finished making all the red petals.
# Now we draw the middle of the flower.

# --------------------------------------------------
# Stage 4: Draw the central yellow part

# Set the turtle drawing colour
turtle.color("yellow") 

# This makes a circle, using the drawing colour
turtle.dot(160)

# Sometimes we need the following line
# Let's include it, just to be safe
turtle.done()
