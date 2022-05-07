import turtle

# A function for creating a new turtle in the correct position
def create_turtle(x):
    new_turtle = turtle.Turtle()
    new_turtle.shape("turtle")
    new_turtle.shapesize(5, 5, 2)

    # Move the turtle to the given x position
    new_turtle.up()
    new_turtle.left(90)
    new_turtle.goto(x, 0)

    return new_turtle

# An event handling function for turtle3
def lightup3(x, y):
    turtle1.fillcolor("black")
    turtle2.fillcolor("black")
    turtle3.fillcolor("yellow")
    
# Create three turtles
turtle1 = create_turtle(-100)
turtle2 = create_turtle(0)
turtle3 = create_turtle(100)

# Assign the event handling functions to the turtles
turtle1.onclick(lightup1)
turtle2.onclick(lightup2)
turtle3.onclick(lightup3)

turtle.done()
