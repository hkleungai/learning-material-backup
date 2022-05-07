def get_info(current_year, year_of_birth):
    chinese_zodiac = [
        "Rat", "Ox", "Tiger", "Rabbit",
        "Dragon", "Snake", "Horse", "Sheep",
        "Monkey", "Rooster", "Dog", "Pig"
    ]

    age = current_year - year_of_birth
    animal = chinese_zodiac[(year_of_birth - 1960) % 12]

    return age, animal

year = int(input("Hi, what is the current year? "))
birthyear = int(input("When is your year of birth? "))

myage, myanimal = get_info(year, birthyear)

print("You are", myage)
print("Your animal is", myanimal)
