"""
In this example the user has to enter the
result of adding two numbers.
We use a while loop to repeatedly ask for the answer
until the user gets it correct.
"""

import random # For this example, we need to tell Python to add the various
              # random functions it has, so we can use one of them

number1 = random.randint(1, 99) # Generate one random number between 1-99
number2 = random.randint(1, 99) # Generate another random number

answer = number1 + number2 # Work out the answer which the user has to guess
guess = 0 # Make the variable for the user's guess

# Keep repeating the loop when the guess is different to the answer
while guess != answer:
    print("What is", number1, "+", number2) # Display a message
    guess = input("? ") # Get the user input and store it
    guess = int(guess) # Convert what the user entered into an integer
        
# If we get this far then the while loop has finished.
# That means the user must have entered a correct answer
# So let's give the user an encouraging message!
print("You are right!")
