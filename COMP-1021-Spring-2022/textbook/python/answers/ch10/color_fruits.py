fruit_colors = { "apple":  "red",
                 "banana": "yellow",
                 "grape":  "purple",
                 "orange": "orange" }

color_fruits = {}
for key, value in fruit_colors.items():
    color_fruits[value] = key
    
print(color_fruits)
