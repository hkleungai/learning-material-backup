import turtle
import time

turtle.tracer(False)  # Turn off the animation

# Draw the Earth using a blue circle and some text
turtle.color("blue")
turtle.dot(100)
turtle.color("white")
turtle.write("Earth", align="center", font=("Arial", 15, "bold"))
turtle.hideturtle()

# Set up the new turtle
moon_turtle = turtle.Turtle()
moon_turtle.forward(200)
moon_turtle.left(90)
moon_turtle.up()
moon_turtle.hideturtle()

while True:  # Run the program forever
    # Clear the Moon only
    moon_turtle.clear()

    # Redraw the Moon using a gray circle and some text
    moon_turtle.color("gray")
    moon_turtle.dot(50)
    moon_turtle.color("white")
    moon_turtle.write("Moon", align="center",font=("Arial",8,"bold"))

    # Rotate the Moon to a new location
    moon_turtle.circle(200, 10)

    # Update the screen and wait for a while
    turtle.update()
    time.sleep(0.1)

turtle.done()
