"""
An example of using a for loop, with 'continue'
"""

for i in range(10):
    if i % 2:       # If i is odd, don't print it
        continue    # Jump to the next loop
    print(i)        # Result is 0 2 4 6 8

print("done!")
