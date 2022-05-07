import turtle

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

# Create an instance of the class
red_circle = Circle(0, 0, 100, "red")
red_circle.draw()

turtle.done()
