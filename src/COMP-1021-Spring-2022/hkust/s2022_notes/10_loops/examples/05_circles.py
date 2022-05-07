import turtle

turtle.color("blue")
turtle.width(10)

radius = 100
while radius > 0:
    turtle.circle(radius)
    radius = radius - 10

turtle.done()
