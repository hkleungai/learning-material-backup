# Demonstration of adding and removing items in dictionaries in Python

# Create a dictionary of the head-location mapping in heads.jpg
heads = {"David":  (589,106,48,63),
         "Gibson": (474,102,44,58),
         "Jogesh": (438,146,45,60),
         "Paul":   (522,162,55,68)}

print("Head and location mapping is:")
print(heads)
print()

# Access one of the items
print("Where is Paul?")
where_is_paul = heads["Paul"]
print(where_is_paul)
print()

# Modify an item
print("David has a smaller head...")
heads["David"] = (588, 104, 48, 57)
print(heads)
print()

# Add an item by assigning the key/value pair to the dictionary
print("Sean has joined us!")
heads["Sean"] = (628,146,46,58)
print(heads)
print()

# Remove an item using the del keyword
print("The president has left us now...")
del heads["Paul"]
print(heads)
print()
