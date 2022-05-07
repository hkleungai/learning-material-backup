def a(n):
    if n == 3:
        return 1
    elif n == 2:
        return 2
    elif n == 1:
        return 3
    elif n == 0:
        return 4
    else:
        return a(n - 1) + a(n - 2) + a(n - 3) + a(n - 4)

print(a(10))
