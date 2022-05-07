import turtle

title = ["Interactive",
         "Python Programming",
         "for Beginners"]

turtle.up()
turtle.goto(0, 40)
turtle.right(90)

for part in title:
    turtle.write(part, align="center", font=("Arial", 30, "bold"))
    turtle.forward(60)
    
turtle.done()
