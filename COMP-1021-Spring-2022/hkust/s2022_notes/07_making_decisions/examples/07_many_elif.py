value = input("Enter a number from 0 to 9: ")
value = int(value)

if value == 0:
    number_in_english = "Zero"
elif value == 1:
    number_in_english = "One"
elif value == 2:
    number_in_english = "Two"
elif value == 3:
    number_in_english = "Three"
elif value == 4:
    number_in_english = "Four"
elif value == 5:
    number_in_english = "Five"
elif value == 6:
    number_in_english = "Six"
elif value == 7:
    number_in_english = "Seven"
elif value == 8:
    number_in_english = "Eight"
elif value == 9:
    number_in_english = "Nine"
else:
    number_in_english = "I don't know!"

print("The number in English is", number_in_english)
