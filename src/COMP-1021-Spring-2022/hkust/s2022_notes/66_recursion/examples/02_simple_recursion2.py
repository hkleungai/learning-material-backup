def printsomenumbers(num):
    if num < 4:
        printsomenumbers(num + 1)
    print(num)

printsomenumbers(0)
