# An example of creating a string and different ways 
# to access the string content using slicing

myword = "funny"

print("The string is        :", end=" ")
print(myword)        # output whole word
print()

print("Output myword[1]     :", end=" ")
print(myword[1])     # output a character

print("Output myword[-4]    :", end=" ")
print(myword[-4])    # output a character

print("Output myword[1:3]   :", end=" ")
print(myword[1:3])   # output a substring from index 1 to index 2

print("Output myword[0:4]   :", end=" ")
print(myword[0:4])   # output a substring from index 0 to index 3

print("Output myword[:3]    :", end=" ")
print(myword[:3])    # output a substring from the start to index 2

print("Output myword[3:]    :", end=" ")
print(myword[3:])    # output a substring from index 3 to the end

print("Output myword[1:5:3] :", end=" ")
print(myword[1:5:3]) # output a substring from index 1 to 4 with step 3, i.e. the second and the fifth characters

print("Output myword[::2]   :", end=" ")
print(myword[::2])   # output the characters in alternate positions

print("Output myword[::-1]  :", end=" ")
print(myword[::-1])  # output the string in reverse order
