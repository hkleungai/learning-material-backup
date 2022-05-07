import turtle
import time

turtle.tracer(False)  # Turn off the animation

# Draw the Sun using a orange circle and some text
turtle.color("orange")
turtle.dot(100)
turtle.color("white")
turtle.write("Sun", align="center", font=("Arial", 15, "bold"))
turtle.hideturtle()

# Set up the Earth turtle
earth_turtle = turtle.Turtle()
earth_turtle.forward(200)
earth_turtle.left(90)
earth_turtle.up()
earth_turtle.hideturtle()

# Set up the Moon turtle
moon_turtle = turtle.Turtle()
moon_turtle.forward(200)
moon_turtle.left(90)
moon_turtle.up()
moon_turtle.hideturtle()

# Moon location based on an angle
moon_angle = 0

x = 0
while True:  # Run the program forever
    # Clear the Earth and the Moon
    earth_turtle.clear()
    moon_turtle.clear()

    # Draw the Earth using a blue circle and some text
    earth_turtle.color("blue")
    earth_turtle.dot(50)
    earth_turtle.color("white")
    earth_turtle.write("Earth", align="center", font=("Arial", 8, "bold"))

    # Draw the Moon
    moon_turtle.right(90)
    moon_turtle.forward(50)
    moon_turtle.left(90)
    moon_turtle.circle(50, moon_angle)
    moon_turtle.color("gray")
    moon_turtle.dot(20)
    moon_turtle.circle(50, -moon_angle)
    moon_turtle.right(90)
    moon_turtle.backward(50)
    moon_turtle.left(90)

    # Rotate the Earth to a new location
    earth_turtle.circle(200, 4)

    # The Moon follow the Earth rotation
    moon_turtle.circle(200, 4)
    moon_angle += 10

    # Update the screen and wait for a while
    turtle.update()
    time.sleep(0.1)

turtle.done()
