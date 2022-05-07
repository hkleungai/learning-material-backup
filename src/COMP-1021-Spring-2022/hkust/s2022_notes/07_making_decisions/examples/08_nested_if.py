import turtle

print("Beautiful Modern Art!")
print()
print("This program will display some beautiful")
print("modern art, according to your choices.")
print()
print("Please choose one of the following.")
print()
print("1 - using squares/rectangles")
print("2 - using turtle.circle")
print()

choice = input("Which one do you want? ")

if choice == "1":
    print("Please choose one of the following.")
    print()
    print("a - simple art using squares/rectangles")
    print("b - advanced art using squares/rectangles")
    print()
    second_choice = input("Which one do you want? ")

    if second_choice == "a":
        # Make the line thick
        turtle.width(50)

        # Change the pen colour and the fill colour
        turtle.color("blue", "red")

        # Draw the box 
        turtle.up()
        turtle.forward(200)
        turtle.down()
        turtle.begin_fill()
        turtle.left(90)
        turtle.forward(200)
        turtle.left(90)
        turtle.forward(400)
        turtle.left(90)
        turtle.forward(400)        
        turtle.left(90)
        turtle.forward(400)        
        turtle.left(90)
        turtle.forward(200)        
        turtle.end_fill()

        
        turtle.up()
        turtle.color("black")
        turtle.goto(170, -270)
        turtle.write("UST", font=("Arial", 22, "normal"))
        turtle.done()
        
    elif second_choice == "b":
        # Make the line thick
        turtle.width(30)

        # Change the pen colour and the fill colour
        turtle.color("cyan", "purple")

        # Draw the first square
        turtle.up()
        turtle.goto(-100, -175)
        turtle.down()
        turtle.begin_fill()
        turtle.forward(175)
        turtle.left(90)
        turtle.forward(350)
        turtle.left(90)
        turtle.forward(350)        
        turtle.left(90)
        turtle.forward(350)        
        turtle.left(90)
        turtle.forward(175)        
        turtle.end_fill()

        # Draw the second square 
        turtle.up()
        turtle.goto(-100, -100)
        turtle.width(10)
        turtle.down()
        turtle.color("black", "grey")
        turtle.begin_fill()
        turtle.forward(350)
        turtle.left(90)
        turtle.forward(200)
        turtle.left(90)
        turtle.forward(350)        
        turtle.left(90)
        turtle.forward(200)        
        turtle.end_fill()

        turtle.up()
        turtle.color("black")
        turtle.goto(150, -270)
        turtle.write("Clarity", font=("Arial", 22, "normal"))
        turtle.done()
    else:
        print("You need to enter a or b!")

elif choice == "2":
    print("Please choose one of the following.")
    print()
    print("a - simple art using turtle.circle")
    print("b - advanced art using turtle.circle")
    print()
    second_choice = input("Which one do you want? ")

    if second_choice == "a":
        # Make the line thick
        turtle.width(50)

        # Change the pen colour and the fill colour
        turtle.color("green")
        turtle.up()
        turtle.goto(-50, -140)
        turtle.down()
        turtle.circle(200)
        
        turtle.up()
        turtle.color("black")
        turtle.goto(120, -270)
        turtle.write("Perpetual", font=("Arial", 22, "normal"))
        turtle.done()
    elif second_choice == "b":
        # Change the pen colour and the fill colour
        turtle.width(20)
        turtle.color("grey")
        turtle.circle(60, 90)

        turtle.width(80)
        turtle.color("pink")
        turtle.circle(140, 45)
        
        turtle.width(150)
        turtle.left(22.5)
        turtle.color("red")
        turtle.circle(200, 22.5)

        turtle.width(200)
        turtle.left(60)
        turtle.color("yellow")
        turtle.circle(400, 50)

        turtle.up()
        turtle.color("black")
        turtle.goto(150, -270)
        turtle.write("Fusion", font=("Arial", 22, "normal"))
        turtle.done()
    else:
        print("You need to enter a or b!")
else:
    print("You need to enter 1 or 2!")
