import turtle

radius = 100  # Initial radius of the rainbow

for color in ["red", "orange", "yellow", "green", "lime", "blue",
              "magenta"]:
    turtle.color("", color)

    # Draw half a circle using each colour in the list
    turtle.begin_fill()
    turtle.forward(radius)
    turtle.left(90)
    turtle.circle(radius, 180)
    turtle.left(90)
    turtle.forward(radius)
    turtle.end_fill()

    # Decrease the radius each time
    radius = radius - 15

turtle.done()
