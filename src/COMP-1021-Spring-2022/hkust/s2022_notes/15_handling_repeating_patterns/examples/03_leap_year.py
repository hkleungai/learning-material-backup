"""
This is an example of showing whether a year is a leap year or common year.
"""

startyear = 2000
endyear = 2015

for year in range(startyear, endyear + 1):
    print(year, end=": ")

    if year % 4 == 0:
        print("leap year")
    else:
        print("common year")
