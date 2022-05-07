"""
An example of using break in a nested loop
"""
for year in range(1, 5):
    money = 8000 + (year * 1000)
    for month in range(1, 13):
        print("Year", year, "month", month, end=": ")
        money = money - 1000
        if money == 0:
            print("No money left, must go home")          
            break
        print("I have enough to stay away from home")
