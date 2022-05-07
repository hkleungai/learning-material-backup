def printsomenumbers(num):
    print(num)
    if num < 4:
        printsomenumbers(num + 1)

printsomenumbers(0)
