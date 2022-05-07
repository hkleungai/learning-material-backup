"""
In this example we pretend a compulsive eater is in a shop
which sells candy bars.
The person keeps buying candy bars until there isn't 
enough money to buy any more.
This is implemented by using a while loop.
The loop stops when the money in the person's pocket
is less than the cost of the candy bar.
"""

money_in_pocket = 30
cost_of_candy_bar = 7

while money_in_pocket >= cost_of_candy_bar:
    print("I have $", money_in_pocket)
    print("I am buying and eating a delicious candy bar!")

    money_in_pocket = money_in_pocket - cost_of_candy_bar

print("Now, I only have $", money_in_pocket, "left.")
print("I don't have enough money for any more candy :(")
