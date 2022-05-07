# The following demonstrates the conversion from a Float to an Integer number
print("The following demonstrates the conversion from a Float to an Integer.")
print()

print("int(0) = ", int(0))
print()

print("int(0.3) = ", int(0.3))
print()

print("int(0.5) = ", int(0.5))
print()

print("int(0.9) = ", int(0.9))
print()

print("int(1.0) = ", int(1.0))
print()

while True:
    number = input("Input a number to convert to Integer: ")
    # convert the input from a string to a float first
    number = float(number)
    # then display the number converted into an integer
    print("int(", number, ") = ", int(number))
    print()
