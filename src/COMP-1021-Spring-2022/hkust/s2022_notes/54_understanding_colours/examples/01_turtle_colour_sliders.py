"""
This example lets the user explore how a single 
colour is created using a combination of
red, green and blue components.
"""

import turtle

# Set the x positions of each turtle
red_turtle_x   = 1
green_turtle_x = 2
blue_turtle_x  = 3

def red_turtle_drag_handler(x, y):
    # Clear the drag handler
    red_turtle.ondrag(None)

    # Fix the x position
    x = red_turtle_x

    # Move the turtle and update the colour
    red_turtle.goto(x, y)
    update_screen_colour()

    # Reassign the drag handler function
    red_turtle.ondrag(red_turtle_drag_handler)

def green_turtle_drag_handler(x, y):
    # Clear the drag handler
    green_turtle.ondrag(None)

    # Fix the x position
    x = green_turtle_x

    # Move the turtle and update the colour
    green_turtle.goto(x, y)
    update_screen_colour()

    # Reassign the drag handler function
    green_turtle.ondrag(green_turtle_drag_handler)

def blue_turtle_drag_handler(x, y):
    # Clear the drag handler
    blue_turtle.ondrag(None)

    # Fix the x position
    x = blue_turtle_x

    # Move the turtle and update the colour
    blue_turtle.goto(x, y)
    update_screen_colour()

    # Reassign the drag handler function
    blue_turtle.ondrag(blue_turtle_drag_handler)

def update_screen_colour():
    # Make sure each value is not greater than 255
    red   = min(red_turtle.ycor(),   255)
    green = min(green_turtle.ycor(), 255)
    blue  = min(blue_turtle.ycor(),  255)

    # Make sure each value is not less than 0
    red   = max(red,   0)
    green = max(green, 0)
    blue  = max(blue,  0)

    # Set the window background colour using RGB
    turtle.bgcolor(int(red), int(green), int(blue))

# The main part of the program follows
# Set up the turtle window
turtle.colormode(255)
turtle.setworldcoordinates(0, 0, 4, 255)
turtle.hideturtle() # We don't want to see the default turtle

# Set up the red turtle
red_turtle = turtle.Turtle()
red_turtle.fillcolor("red")
red_turtle.shape("turtle")
red_turtle.shapesize(4, 4, 4)
red_turtle.speed(0)
red_turtle.up()
red_turtle.goto(red_turtle_x, 0)
red_turtle.left(90)
red_turtle.ondrag(red_turtle_drag_handler)

# Set up the green turtle
green_turtle = turtle.Turtle()
green_turtle.fillcolor("green")   
green_turtle.shape("turtle")      
green_turtle.shapesize(4, 4, 4)
green_turtle.speed(0)
green_turtle.up()
green_turtle.goto(green_turtle_x, 0)
green_turtle.left(90)
green_turtle.ondrag(green_turtle_drag_handler)

# Set up the blue turtle
blue_turtle = turtle.Turtle()
blue_turtle.fillcolor("blue")
blue_turtle.shape("turtle")
blue_turtle.shapesize(4, 4, 4)
blue_turtle.speed(0)
blue_turtle.up()
blue_turtle.goto(blue_turtle_x, 0)
blue_turtle.left(90)
blue_turtle.ondrag(blue_turtle_drag_handler)

update_screen_colour() # Show the first RGB colour

turtle.done() # Handle the dragging events
