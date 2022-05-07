import turtle

# Initialise the important variables
branch_length = 100
branch_angle = 30
max_depth = 1  # This is the maximum depth of the resulting tree
               # You can change it to any value you like

def buildtree(depth):
    # Draw the line for this trunk/branch
    turtle.forward(branch_length)

    if depth < max_depth:
        # Recursively draw the left branch
        turtle.left(branch_angle)
        buildtree(depth + 1)

        # Recursively draw the right branch
        turtle.right(branch_angle * 2)
        buildtree(depth + 1)

        # Restore the turtle orientation
        turtle.left(branch_angle)

    # Back to the starting position
    turtle.backward(branch_length)

# Turn off animation
turtle.tracer(False)

# Set up the turtle
turtle.hideturtle()
turtle.width(2)

# Move the turtle to the starting position of the tree
turtle.up()
turtle.left(90)
turtle.backward(200)
turtle.down()

# Build the tree from depth level 0
buildtree(0)

# Show the result
turtle.update()

turtle.done()
