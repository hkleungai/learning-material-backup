import turtle

turtle.color("brown")
turtle.speed(0)
turtle.up()

y=0
while y<10:

    x=0
    while x<10:
        display_x=x*20
        display_y=y*20
        turtle.goto(display_x, display_y)
        turtle.dot(20) # This works even if the pen is off the page
        x=x+1

    y=y+1

print("finished!")
turtle.done()

