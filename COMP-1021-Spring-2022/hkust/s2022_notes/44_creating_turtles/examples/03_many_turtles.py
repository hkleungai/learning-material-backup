"""
This example creates 5 turtles.
The turtles are rotated and moved randomly.
"""

import turtle
import random

# Create a new turtle, set its parameters, add it to the list 
def createOneTurtle(thisColor):
    thisTurtle = turtle.Turtle()   # Make a new turtle object
    thisTurtle.fillcolor(thisColor)# Set the color of the turtle
    thisTurtle.shape("turtle")     # Change to "turtle" shape
    thisTurtle.shapesize(2, 2)     # Make the turtle twice as big
    thisTurtle.up()                # Do this so no line drawn
    thisTurtle.goto(random.randint(-80, 80),
                    random.randint(-80, 80)) # Starting position
    allTurtles.append(thisTurtle)  # Append the turtle to the list

# Select a random turtle, change its angle randomly
# and move it forward a random distance
def changeOneTurtle():
    index = random.randint(0, 4) # Select a random index
    allTurtles[index].left(random.randint(-90, 90)) # Change angle
    allTurtles[index].forward(random.randint(10, 15)) # Move it
    
########################################
# This is the main part of the program
turtle.hideturtle() # Hide the default turtle, we don't use it

# A list for managing the turtles
allTurtles = []

# Create the turtles one by one
# using a different colour each time
createOneTurtle("red")
createOneTurtle("green")
createOneTurtle("blue")
createOneTurtle("cyan")
createOneTurtle("magenta")

# Start moving the turtles
while True:
    changeOneTurtle()

turtle.done() # Must have this at the end
