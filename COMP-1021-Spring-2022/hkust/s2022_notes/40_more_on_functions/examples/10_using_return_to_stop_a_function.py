def donate(money):
    if money <= 0:
        # Stop the function when
        # the value is a silly one
        return

    # Print a message if the value is okay
    print("Thank you! You are so generous!")

donation = int(input("How much do you donate? "))
donate(donation)
