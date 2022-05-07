import turtle

def draw_polygon(length, sides):
    for _ in range(sides):
        turtle.forward(length)
        turtle.left(360 / sides)   

draw_polygon(60, 6)

turtle.done()
