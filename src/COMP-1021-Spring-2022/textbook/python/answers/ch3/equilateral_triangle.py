import turtle

length = input("What is the side length of the triangle? ")
length = int(length)

turtle.forward(length)
turtle.left(120)
turtle.forward(length)
turtle.left(120)
turtle.forward(length)

turtle.done()
