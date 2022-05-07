import turtle

# A list of lists containing a telephone directory
directory = [ ["Mary",  "Johnson", "1245035"],
              ["John",  "Moody",   "1928356"],
              ["Andy",  "Chung",   "1567860"],
              ["Molly", "Li",      "1214213"],
              ["Jane",  "Foster",  "1506932"] ]

# Move to the starting point
turtle.up()
turtle.goto(-180, 100)

for entry in directory:  # Look at each telephone entry
    # Write the first name
    turtle.write(entry[0], font=("Times", 20, "normal"))
    turtle.forward(100)

    # Write the last name in uppercase letter using bold text
    turtle.write(entry[1].upper(), font=("Times", 20, "bold"))
    turtle.forward(150)

    # Write the telephone number
    turtle.write(entry[2], font=("Arial", 18, "normal"))

    # Move to the position of the next entry
    turtle.backward(250)
    turtle.right(90)
    turtle.forward(40)
    turtle.left(90)

turtle.done()
