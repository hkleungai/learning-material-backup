# Demonstration of other things one can do with lists 

# Sort the list in increasing number/letter order
words = ["cat", "dog", "apple", "bat"]
print("words = ", words)
words.sort()
print("After sorting:")
print("words = ", words)
print()

# Reverse the content of the list
words = ["cat", "dog", "apple", "bat"]
print("words = ", words)
words.reverse()
print("After reversing:")
print("words = ", words)
print()

# Count how many times something appears
ages = [20,21,19,20,19,22,20,20,20,18]
print("ages = ", ages)
print("ages.count(20) = ", ages.count(20))
print()

# Find the first occurrence of something
ages = [20,21,19,20,19,22,20,20,20,18]
print("ages = ", ages)
print("ages.index(19) = ", ages.index(19))
print()

# Append another list to this list
happywords = ["I", "love", "you"]
print("happywords = ", happywords)
happywords.extend(["if","you","lend","me","money"])
print('After extending with ["if","you","lend","me","money"]":')
print("happywords = ", happywords)
