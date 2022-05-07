import turtle

text = "RAINBOW"

turtle.up()
turtle.forward(200)
turtle.left(90)

for letter in text[::-1]:
    turtle.write(letter, align="center", font=("Arial", 40, "bold"))
    turtle.circle(200, 180 / (len(text) - 1))

turtle.done()
