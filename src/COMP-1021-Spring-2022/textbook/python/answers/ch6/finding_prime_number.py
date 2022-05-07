x = int(input("Please give me a number: "))

prime = True
for factor in range(2, int(x / 2) + 1):
    if x % factor == 0:
        prime = False

if prime:
    print("It is a prime number.")
else:
    print("It is not a prime number.")    
