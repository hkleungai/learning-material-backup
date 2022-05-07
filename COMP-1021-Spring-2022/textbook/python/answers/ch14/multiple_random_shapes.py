import turtle
import random

turtle.speed(0)

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

class Square:
    # The constructor of the class that initialises the attributes
    def __init__(self, x, y, length, color):
        self.x = x
        self.y = y
        self.length = length
        self.color = color

    # The method to draw the square in the turtle window
    def draw(self):
        # Move the turtle to the bottom left corner of the square
        turtle.up()
        turtle.goto(self.x - self.length / 2, self.y - self.length / 2)
        turtle.setheading(0)
        turtle.down()

        # Draw the square
        turtle.fillcolor(self.color)
        turtle.begin_fill()
        for _ in range(4):
            turtle.forward(self.length)
            turtle.left(90)
        turtle.end_fill()

# The list of colours
colors = ["red", "green", "blue", "yellow", "cyan", "magenta", "black"]

# Create 30 circles and squares randomly
shapes = []
for _ in range(30):
    x = random.randint(-200, 200)
    y = random.randint(-200, 200)
    radius = random.randint(10, 50)
    color = random.choice(colors)

    # Create a new circle and append it to the list
    circle = Circle(x, y, radius, color)
    shapes.append(circle)

    x = random.randint(-200, 200)
    y = random.randint(-200, 200)
    length = random.randint(20, 100)
    color = random.choice(colors)

    # Create a new square and append it to the list
    square = Square(x, y, length, color)
    shapes.append(square)

# Draw the shapes
for shape in shapes:
    shape.draw()

turtle.done()
