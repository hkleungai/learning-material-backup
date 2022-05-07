def max(number1, number2, number3):
    if number1 > number2:
        if number1 > number3:
            return number1
        else:
            return number3
    else:
        if number2 > number3:
            return number2
        else:
            return number3

n1 = 12
n2 = 5
n3 = 78
n4 = 34
n5 = 23
n6 = 93
n7 = 25
n8 = 11
n9 = 70

print(max(max(n1, n2, n3), max(n4, n5, n6), max(n7, n8, n9)))
