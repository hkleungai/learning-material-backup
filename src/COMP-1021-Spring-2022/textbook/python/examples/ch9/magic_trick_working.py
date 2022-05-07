def magic_trick():
    global your_money
    if your_money < 1000:
        your_money = your_money + 500

your_money = int(input("How much do you have? "))
magic_trick()
print("You have $" + str(your_money) + " now!")
