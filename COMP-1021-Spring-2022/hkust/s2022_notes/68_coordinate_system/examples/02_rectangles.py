import turtle

# A simple function for drawing a rectangle
def draw_rectangle(height):
    for _ in range(2):
        turtle.forward(1)
        turtle.left(90)
        turtle.forward(height)
        turtle.left(90)

# These are the rectangle heights
values=[7, 2, 8, 10, 6]

# Change the coordinate system
# so it is more suitable for the data
turtle.setworldcoordinates(0, 0, 5, 10) 

turtle.color("orange")
turtle.speed(0)
turtle.width(5)

# Go through each index, draw a rectangle
# using the value at that index position as the height
for x in range(len(values)):
    turtle.goto(x, 0)
    draw_rectangle(values[x])

turtle.done()
