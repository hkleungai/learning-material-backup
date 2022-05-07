"""
In this example the user has to enter the result of adding two numbers.
We use a while loop to ask for the answer until the user gets it correct.
The user only needs to answer three different questions in the program.
"""

import random # For this example, we need to tell Python to add the various
              # random functions it has, so we can use one of them

number_of_questions_so_far = 0 # Keep track of the number of questions asked

while number_of_questions_so_far < 3: # Keep asking until we are done
    number1 = random.randint(1, 99) # Generate one random number
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

    # Increase the number of questions
    number_of_questions_so_far = number_of_questions_so_far + 1
