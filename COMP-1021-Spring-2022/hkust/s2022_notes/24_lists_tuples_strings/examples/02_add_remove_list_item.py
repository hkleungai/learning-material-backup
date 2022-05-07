# Demonstration of inserting, removing and appending list items 

# Create a list
comment = ["Dave", "is", "human"]
print("comment = ", comment)
print()

# Insert a new item in the list at position 2
print("Add a new item:")
comment.insert(2, "not")
print("comment = ", comment)
print()

# Remove an item from the list with the content "human"
print("Remove an item:")
comment.remove("human")
print("comment = ", comment)
print()

# Append an item to the end of the list
print("Append a new item:")
comment.append("evil!")
print("comment = ", comment)
