import turtle

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

red_square = Square(0, 0, 100, "red")
red_square.draw()

turtle.done()
