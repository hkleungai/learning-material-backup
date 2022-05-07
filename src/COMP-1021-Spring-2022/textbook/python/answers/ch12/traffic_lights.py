import turtle

# Use turtles to show the light colours
def create_turtle():
    new_turtle = turtle.Turtle()
    new_turtle.shape("circle")
    new_turtle.shapesize(0.8 * width / 20, 0.8 * width / 20)
    new_turtle.color("gray")
    new_turtle.up()
    return new_turtle

width = 100
height = 300

turtle.tracer(False)

# Make the black box
turtle.left(90)
turtle.shape("square")
turtle.shapesize(width / 20, height / 20)

# Create the three lights
turtle1 = create_turtle()
turtle1.goto(0, -width)
turtle2 = create_turtle()
turtle2.goto(0, 0)
turtle3 = create_turtle()
turtle3.goto(0, width)

# Show green light
def stage1():
    turtle1.color("green")
    turtle2.color("gray")
    turtle3.color("gray")
    turtle.update()

# Show yellow light
def stage2():
    turtle1.color("gray")
    turtle2.color("yellow")
    turtle3.color("gray")
    turtle.update()

# Show red light
def stage3():
    turtle1.color("gray")
    turtle2.color("gray")
    turtle3.color("red")
    turtle.update()

# Show red and yellow light
def stage4():
    turtle1.color("gray")
    turtle2.color("yellow")
    turtle3.color("red")
    turtle.update()

# Show the lights based on the timing
stage1()
turtle.ontimer(stage2, 4000)
turtle.ontimer(stage3, 5000)
turtle.ontimer(stage4, 9000)
turtle.ontimer(stage1, 10000)

turtle.done()
