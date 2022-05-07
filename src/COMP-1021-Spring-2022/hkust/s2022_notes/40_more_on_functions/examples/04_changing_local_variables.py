def magic_trick(money):
    if money < 1000:
        money = money + 500

money = int(input("How much do you have? "))
magic_trick(money)
print("You have $" + str(money) + " now!")
