"""
An example of using a for loop, with 'break'
"""

for i in range(10):
    if i % 2:       # If i is odd, don't print it
        break       # Jump out of the loop
    print(i)        # Result is 0

print("done!")
