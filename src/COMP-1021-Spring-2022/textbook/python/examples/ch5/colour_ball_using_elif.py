import turtle

# Ask for the colour of the 'ball'
print("Do you like a red ball, a green ball or a blue ball?")
color = input("Please enter red, green or blue: ")

if color == "red":        # If the colour is red...
    turtle.color("red")
    turtle.dot(200)
    turtle.done()
elif color == "green":    # If the colour is green...
    turtle.color("green")
    turtle.dot(200)
    turtle.done()
elif color == "blue":     # If the colour is blue...
    turtle.color("blue")
    turtle.dot(200)
    turtle.done()
else:                     # The colour is not red, green or blue
    print("Please enter red, green or blue only!")
