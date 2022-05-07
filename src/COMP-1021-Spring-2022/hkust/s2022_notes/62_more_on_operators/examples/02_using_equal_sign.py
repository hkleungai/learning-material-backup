"""
This example shows that you can use a shortcut to write an equal sign with
some arithmetic operators when you put the result back to the same varible.
"""

calorie = 3500
calorie += 800      # i.e. calorie = calorie + 800
print(calorie)

pigs = 6
pigs *= 5           # i.e. pigs = pigs * 5
print(pigs)

cakes, students = 40, 8
cakes /= students   # i.e. cakes = cakes / students
print(cakes)

marks = 100
marks -= 20         # i.e. marks = marks - 20
print(marks)

hello = "Hello"
hello += "!"        # i.e. hello = hello + "!"
print(hello)
