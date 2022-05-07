# The following demonstrates rounding from a Float to an Integer number
print("The following demonstrates rounding from a Float to an Integer.")
print()

print("round(0) = ", round(0))
print()

print("round(0.3) = ", round(0.3))
print()

print("round(0.5) = ", round(0.5))
print()

print("round(0.9) = ", round(0.9))
print()

print("round(1.0) = ", round(1.0))
print()

print("round(1.5) = ", round(1.5))
print()

print("round(2.5) = ", round(2.5))
print()

print("round(3.5) = ", round(3.5))
print()

print("round(4.5) = ", round(4.5))
print()

while True:
    number = input("Input a number to round to Integer: ")
    # convert the input from a string to a float first
    number = float(number)
    # then display the number rounded into an integer
    print("round(", number, ") = ", round(number))
    print()
