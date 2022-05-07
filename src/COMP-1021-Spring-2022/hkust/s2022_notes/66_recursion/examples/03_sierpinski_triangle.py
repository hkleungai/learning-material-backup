"""
This python program draws triangles
recursively, in the Sierpinski style.

First, a large black triangle is drawn.
Then the recursive function is called.

The recursive function draws a white
triangle in the middle. Then it calls
itself three times to handle the three
'corner' black triangles.

The user can control the maximum
depth of recursion by pressing
any digit key, 0-9.

However, you may have to wait 
a long time to see the results of
pressing the higher numbers i.e 7 
and above, because the recursive 
function will be executed many times.
"""

import turtle

# The variable which stores
# the value of maximum depth,
# which can be varied by the user
max_depth = 3

# Screen width and height
width = 500
height = 500

# The following 10 functions are
# event handlers. They are executed
# when the corresponding digit
# key is pressed on the keyboard.
def setMaxDepth0():
    global max_depth
    max_depth = 0
    clearScreenAndDrawTriangles()

def setMaxDepth1():
    global max_depth
    max_depth = 1
    clearScreenAndDrawTriangles()

def setMaxDepth2():
    global max_depth
    max_depth = 2
    clearScreenAndDrawTriangles()

def setMaxDepth3():
    global max_depth
    max_depth = 3
    clearScreenAndDrawTriangles()

def setMaxDepth4():
    global max_depth
    max_depth = 4
    clearScreenAndDrawTriangles()

def setMaxDepth5():
    global max_depth
    max_depth = 5
    clearScreenAndDrawTriangles()

def setMaxDepth6():
    global max_depth
    max_depth = 6
    clearScreenAndDrawTriangles()

def setMaxDepth7():
    global max_depth
    max_depth = 7
    clearScreenAndDrawTriangles()

def setMaxDepth8():
    global max_depth
    max_depth = 8
    clearScreenAndDrawTriangles()

def setMaxDepth9():
    global max_depth
    max_depth = 9
    clearScreenAndDrawTriangles()

# This function is just a simple
# function to write some text
# at a particular position
def writeText(x, y, text):
    turtle.up()
    turtle.goto(x, y)
    turtle.down()
    turtle.write(text, font=("Arial", 10, "normal"))

# Create a filled triangle
# using the 3 points stored 
# in the list 'vertices'
def fillTriangle(vertices):
    turtle.up()
    turtle.goto(vertices[0]) # First point
    turtle.begin_fill()
    turtle.goto(vertices[1]) # Second point
    turtle.goto(vertices[2]) # Third point
    turtle.end_fill()
    turtle.update()

# Clear the screen, draw the triangles,
# and show some instructions
def clearScreenAndDrawTriangles():
    global max_depth
        
    turtle.clear()

    # Define the three points of the starting triangle
    vertices = [ (0, height/2), # top point
                 (-width/2, -height*.4), # left point
                 (width/2, -height*.4) ] # right point

    # To get started, we draw
    # one large black triangle
    turtle.color("black")
    fillTriangle(vertices)
        
    # Begin the recursion process.
    # The parameters are: the list of 
    # 3 triangle vertices, the current depth (0)
    Sierpinski(vertices, 0)

    # Show the maximum depth value
    # and some instructions in the
    # bottom left corner of the screen
    turtle.color("black")
    writeText(-width/2+10, -height/2+30, "Maximum depth = " + str(max_depth))
    writeText(-width/2+10, -height/2+15, "Change the depth by pressing the appropriate digit key.")
    turtle.update()

# The recursive function
def Sierpinski(vertices, depth):
    global max_depth

    # To make it easier to understand what's happening, 
    # here's an example of a triangle stored in a list:
    # [ (0, 250), (250, -200), (-250, -200) ]

    # Calculate the middle point of each
    # of the three sides of the triangle
    x1 = (vertices[0][0] + vertices[1][0]) / 2.0
    y1 = (vertices[0][1] + vertices[1][1]) / 2.0
    midPoint1 = (x1, y1)
        
    x2 = (vertices[1][0] + vertices[2][0]) / 2.0
    y2 = (vertices[1][1] + vertices[2][1]) / 2.0
    midPoint2 = (x2, y2)
        
    x3 = (vertices[0][0] + vertices[2][0]) / 2.0
    y3 = (vertices[0][1] + vertices[2][1]) / 2.0
    midPoint3 = (x3, y3)

    # The background is a black triangle, 
    # so we always draw white triangles
    turtle.color("white")

    # Draw the middle white triangle
    fillTriangle([midPoint1, midPoint2, midPoint3])
        
    # If we haven't yet reached the maximum depth
    # of recursion, call this function three times,
    # once for the top triangle, once for the left
    # triangle, once for the right triangle
    if depth < max_depth:

        # When we recursively call this function we 
        # give the function a new triangle list
        # and we increase the value of the current depth
        # so the next function knows what depth it is
        
        # Recursively call Sierpinski() to draw the top triangle
        Sierpinski([vertices[0], midPoint1, midPoint3], depth + 1)
        
        # Recursively call Sierpinski() to draw the left triangle
        Sierpinski([midPoint1, vertices[1], midPoint2], depth + 1)
        
        # Recursively call Sierpinski() to draw the right triangle
        Sierpinski([midPoint3, midPoint2, vertices[2]], depth + 1)


# The main part of the program

# Set up the screen display
turtle.setup(width, height)
turtle.bgcolor("white")

# Set the title of the window
turtle.title("Recursion Example - Drawing Sierpinski Triangle")

# We don't want to see the turtle activity
turtle.tracer(False)
turtle.hideturtle()

# Set up event handler functions so the 
# user can easily change the maximum depth
turtle.onkeypress(setMaxDepth0, "0")
turtle.onkeypress(setMaxDepth1, "1")
turtle.onkeypress(setMaxDepth2, "2")
turtle.onkeypress(setMaxDepth3, "3")
turtle.onkeypress(setMaxDepth4, "4")
turtle.onkeypress(setMaxDepth5, "5")
turtle.onkeypress(setMaxDepth6, "6")
turtle.onkeypress(setMaxDepth7, "7")
turtle.onkeypress(setMaxDepth8, "8")
turtle.onkeypress(setMaxDepth9, "9")

# Draw everything
clearScreenAndDrawTriangles()

# Listen for any keys being pressed
turtle.listen()

turtle.done()
