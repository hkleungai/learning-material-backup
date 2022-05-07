# Demonstration of traversing a dictionary in Python

# Create a dictionary of the head-location mapping in heads.jpg
heads = {"David":  (588,104,48,57),
         "Gibson": (474,102,44,58),
         "Jogesh": (438,146,45,60),
         "Paul":   (522,162,55,68)}

# Print the dictionary by traversing the data using a for loop
print("All the information in the dictionary:")
for key, value in heads.items():
    print(key, value)
print()

# Print the keys only
print("The people are:")
for key in heads.keys():
    print(key)
print()

# Print the values only
print("The positions and dimensions are:")
for value in heads.values():
    print(value)
print()

# Check the existence of an item
print("Is David in the picture?")
if "David" in heads:
    print("He is there!")
