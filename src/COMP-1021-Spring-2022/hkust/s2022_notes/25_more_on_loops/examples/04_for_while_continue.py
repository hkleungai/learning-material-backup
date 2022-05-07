"""
An example of using continue in a for loop and a while loop
"""
# Use continue in a for loop
for i in range(5):
    if i == 2:
        continue
    print(i)

# Use continue in a while loop
i = 0
while i < 5:
    if i == 2:
        i = i + 1
        continue
    print(i)
    i = i + 1