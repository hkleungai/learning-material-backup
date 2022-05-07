# Demonstration of using two dimensional lists in Python

# Create a one dimensional list
text = ["j", "o", "k", "e", "s"]
print("One dimensional list is:")
print(text)
print()

# Ask for the column index to display
col = input("Please enter the column you want to display (0 to 4)? ")
col = int(col)

# Print out the value of that column
print("The value is ", text[col])
print()

# Create a two dimensional list
text = [["h", "a", "r", "r", "y"],
        ["l", "i", "k", "e", "s"],
        ["j", "o", "k", "e", "s"]]

print("Two dimensional list is:")
print(text)
print()

# Ask for the row index to display
row = input("Please enter the row you want to display (0 to 2)? ")
row = int(row)

# Ask for the column index to display
col = input("Please enter the column you want to display (0 to 4)? ")
col = int(col)

# Print out the value of that row and column
print("The value is ", text[row][col])
