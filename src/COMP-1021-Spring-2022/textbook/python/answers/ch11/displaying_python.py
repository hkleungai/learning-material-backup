import turtle
import time

word = "PYTHON"

turtle.up()
turtle.hideturtle()
turtle.backward(200)
turtle.speed(0)

for letter in word:
    turtle.write(letter, align="center", font=("Arial", 50, "bold"))
    turtle.forward(80)
    time.sleep(1)

turtle.done()
