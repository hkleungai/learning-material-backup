'''
This Python program draws a square in the turtle window using
turtle.goto. This is done by telling the turtle to draw between
the four corners of the square.
'''

# Tell Python to start using the turtle module
import turtle

"""
The turtle draws a square by drawing between the four corners
of the square in an anti-clockwise order.
"""
turtle.goto(120, 0)
turtle.goto(120, 120)
turtle.goto(0, 120)
turtle.goto(0, 0)

turtle.done() # The program tells turtle graphics that everything is done
