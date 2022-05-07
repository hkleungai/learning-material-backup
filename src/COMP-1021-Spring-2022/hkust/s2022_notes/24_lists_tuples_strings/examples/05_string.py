# Demonstration of strings in Python

print("A 'string' is the name for text in the world of computing.")
print("Python thinks a 'string' as a 'tuple' of letters")
print()

#create a new string using a pair of double quotations
mytext="Hello" #this is the same as mytext='Hello'

# Print the current content of the string
print("Current string is '"+mytext+"'")
print()

# Ask for an index of the string
index = input("Please enter the index of the character you want to access (0-4): ")
index = int(index)
print()

# Print the current value of the index
# The str() function changes the data type from an integer to a string
print("Current character at index " + str(index) + " is '" + mytext[index]+"'")
print()

# Print the length of the string
print("The string '"+mytext+"'"+" contains "+str(len(mytext))+" character(s)")
print()

# Count the number of "l" in the string
print("The string '"+mytext+"'"+" contains "+str(mytext.count('l'))+" 'l'")
print()

# Check the first occurrence of "o" in the string
print("The first occurrence of the character 'o' in the string is at the index "+str(mytext.index("o")))
print()

# Ask whether you want to change the string
answer = input("Do you want me to try to modify the string (y or n)? ")
print()

if answer == "y":
    # Ask for the index of the character to be changed in the string
    index = int(input("Please enter the index of the character you want to change (0-4): "))
    value = input("Please input the new character: ")
    # Change the character in the string
    mytext[index] = value # Not allowed, will give error
