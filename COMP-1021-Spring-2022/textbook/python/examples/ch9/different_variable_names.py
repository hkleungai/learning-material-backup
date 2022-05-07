# A list of lists containing a telephone directory
directory = [ ["Mary",  "Johnson", "1245035"],
              ["John",  "Moody",   "1928356"],
              ["Andy",  "Chung",   "1567860"],
              ["Molly", "Li",      "1214213"],
              ["Jane",  "Foster",  "1506932"] ]

def search(name):
    # Look for the name in the directory
    for entry in directory:
        if name == entry[0] or name == entry[1]:
            # Return the full name and telephone number
            return entry[0] + " " + entry[1], entry[2]

    # Return nothing (None) when the name cannot be found
    return None, None

input_name = input("Please enter the name you want to search: ")

# Search the name and store the result in two variables
full_name, telephone = search(input_name)

# Show the result
if full_name == None:  # If nothing is found
    print("The name cannot be found!")
else:
    print(full_name + ": " + telephone)
