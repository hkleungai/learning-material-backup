number = int(input("Please give me a number between 1 and 999: "))

units = number % 10
number = (number - units) // 10
tens = number % 10
number = (number - tens) // 10
hundreds = number % 10

print("The hundreds, tens and units places are " +
      str(hundreds) + ", " + str(tens) + " and " + str(units) +
      " respectively.")
