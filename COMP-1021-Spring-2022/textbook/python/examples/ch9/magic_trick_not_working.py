def magic_trick(money):
    if money < 1000:
        money = money + 500

your_money = int(input("How much do you have? "))
magic_trick(your_money)
print("You have $" + str(your_money) + " now!")
