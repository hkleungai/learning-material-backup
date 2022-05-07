# Demonstration of the difference of using
# index and content lists and dictionaries in Python

# Create two list of the fruit-colour mapping
print("1) Create a fruit and colour mapping using lists")
print()

fruit = ["apple", "grapes", "mango", "orange"]
print("The fruit list is ", fruit)

colour = ["red", "purple", "yellow", "orange"]
print("The colour list is ", colour)
print()

# Ask for the fruit to look for
q = input("Which fruit do you want to look at (apple, grapes, mango or orange)? ")
while q not in fruit:
    print("Please enter a valid fruit.")
    print()
    q = input("Which fruit do you want to look at (apple, grapes, mango or orange)? ")

print()

# Get the index of the fruit in the fruit list
print("Getting the index of the fruit... ", end="")
i = fruit.index(q)
print(i)
print()

# Get the colour of the fruit in the colour list
c = colour[i]
print("The colour of the fruit is", c)
print()

input("Press 'enter' to continue...")
print()

# Create a dictionary of the fruit-colour mapping
print("2) Create a fruit and colour mapping using a dictionary")
print()

mapping = {"apple":"red", "grapes":"purple", "mango":"yellow", "orange":"orange"}
print("The dictionary is ", mapping)
print()

# Ask for the fruit to look for
q = input("Which fruit do you want to look at (apple, grapes, mango or orange)? ")
while q not in mapping:
    print("Please enter a valid fruit.")
    print()
    q = input("Which fruit do you want to look at (apple, grapes, mango or orange)? ")

print()

# Get the colour of the fruit in the fruit-colour mapping
c = mapping[q]
print("The colour of the fruit is", c)
