import turtle

# This is the recursive function for building a tree
def buildtree(current_depth):
    if current_depth <= max_depth:
        # Move along the branch
        turtle.forward(branch_length)

        # Draw the right child branch
        turtle.right(angle_between_branches / 2)
        buildtree(current_depth + 1)

        # Draw the left child branch
        turtle.left(angle_between_branches)
        buildtree(current_depth + 1)

        # Move back to the start point of the branch
        turtle.right(angle_between_branches / 2)
        turtle.backward(branch_length)

# Set up turtle
turtle.color("darkgreen")
turtle.hideturtle()
turtle.width(3)

# Set up some variables about how the tree looks like
branch_length = 60              # This is the length of a branch
angle_between_branches = 40     # This is the angle between two branches
max_depth = 3                   # The maximum depth to draw the tree

# Point the turtle upwards to get started
turtle.left(90)

# Start building the tree from depth 0
buildtree(0)

turtle.done()
