# Demonstration of the string restriction on item assignment

# The following string is to be processed
lunch = "I love to eat a pineapple bun!"

# Print the description of the program
print("A string, called lunch, has been created in this program.")
print()
print("    lunch = \"I love to eat a pineapple bun!\"")
print()
print("Which one of the following statements do you want to try:")
print()
print("1) lunch[-2] = \"g\"")
print()
print("2) lunch[2:6] = \"hate\"")
print()

answer = input("Please enter 1 or 2: ")
answer = int(answer)
print ()

if answer == 1:
    lunch[-2] = "g"     # Not allowed!
elif answer == 2:
    lunch[2:6] = "hate" # Also not allowed!
else:
    print ("Please enter 1 or 2")
