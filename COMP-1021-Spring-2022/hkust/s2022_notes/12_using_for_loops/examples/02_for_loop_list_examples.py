"""
Some examples of using a for loop with 'range'
"""

for i in range(6):      
    print(i, end=" ")   # Result is 0 1 2 3 4 5

print()    # Output an end-of-line simply to make the display clearer

for i in range(0, 6):   
    print(i, end=" ")   # Result is 0 1 2 3 4 5

print()    # Output an end-of-line simply to make the display clearer

for i in range(1, 6, 2):# The third parameter is the 'step'
    print(i, end=" ")   # so this will generate 1 3 5

print()    # Output an end-of-line simply to make the display clearer

for i in [33, 19, 5, -7]:   # A fixed list is used here
    print(i, end=" ")       # Result is 33 19 5 -7
    
print()    # Output an end-of-line simply to make the display clearer

for word in ["How", "are", "you"]:   # A fixed list of words is used here
    print(word, end=" ")             # Result is How are you

