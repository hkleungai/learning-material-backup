import turtle
import time

# Turn off the animation
turtle.tracer(False)

# Draw the pattern using four colours
for color in ["red", "green", "blue", "yellow"]:
    turtle.color(color)
    
    # Draw a pattern using 36 squares
    for _ in range(36):
        for _ in range(4):
            turtle.forward(100)
            turtle.left(90)
        turtle.left(10)

    # Update the screen after drawing
    turtle.update()

    # Wait for 1 second
    time.sleep(1)

turtle.done()
