import turtle
import random

class Circle:
    # The constructor of the class that initialises the attributes
    def __init__(self, x, y, radius, color):
        self.x = x
        self.y = y
        self.radius = radius
        self.color = color

    # The method to draw the circle in the turtle window
    def draw(self):
        # Move the turtle to the right hand side of the circle
        turtle.up()
        turtle.goto(self.x + self.radius, self.y)
        turtle.setheading(90)
        turtle.down()

        # Draw the full circle with the color
        turtle.fillcolor(self.color)
        turtle.begin_fill()
        turtle.circle(self.radius)
        turtle.end_fill()

# The list of colours
colors = ["red", "green", "blue", "yellow", "cyan", "magenta", 
          "black"]

# Create 30 circles randomly
circles = []
for _ in range(30):
    x = random.randint(-200, 200)
    y = random.randint(-200, 200)
    radius = random.randint(10, 50)
    color = random.choice(colors)

    # Create a new circle and append it to the circles list
    circle = Circle(x, y, radius, color)
    circles.append(circle)

# Draw the circles
for circle in circles:
    circle.draw()

turtle.done()
