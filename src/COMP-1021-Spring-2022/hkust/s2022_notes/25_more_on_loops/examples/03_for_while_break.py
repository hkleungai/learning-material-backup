"""
An example of using break in a for loop and a while loop
"""
# Use break in a for loop
for i in range(5):
    if i == 2:
        break
    print(i)

# Use break in a while loop
i = 0
while i < 5:
    if i == 2:
        break
    print(i)
    i = i + 1
