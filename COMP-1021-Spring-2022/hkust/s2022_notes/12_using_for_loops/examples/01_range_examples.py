"""
Examples of the range() function
"""

# Generates [0,1,2,3,4,5,6,7,8,9]
print("range(10) is", list(range(10)))

# Generates [2,3,4,5,6,7,8,9]
print("range(2, 10) is", list(range(2, 10)))

# Generates [1,3,5,7,9] i.e. odd numbers
print("range(1, 10, 2) is", list(range(1, 10, 2)))

# Generates [2,4,6,8] i.e. even numbers
print("range(2, 10, 2) is", list(range(2, 10, 2)))

# Generates [-1,-3,-5,-7,-9]
print("range(-1, -10, -2) is", list(range(-1, -10, -2)))

# Return [] (an empty list) because the default value of step is +1
print("range(10, 1) is", list(range(10, 1)))

# Return [] (an empty list) because the step value is not positive
print("range(-10, 1, -1) is", list(range(-10, 1, -1)))
