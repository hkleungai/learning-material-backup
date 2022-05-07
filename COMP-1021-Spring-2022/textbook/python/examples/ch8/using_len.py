students = ["Mary", "John", "Andy", "Molly", "Jane"]

# Go through the list using the item indices
for index in range(len(students)):
    print(index + 1, end=": ")  # Print the index number (plus 1)
    print(students[index])      # Print the student name
