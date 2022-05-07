# Asking for the weight and height
weight = float(input("How heavy are you (in kg)? "))
height = float(input("How tall are you (in cm)? "))

# The formulation of the BMI value
BMI = weight / (height / 100.0) ** 2

# Showing the results
print("Your BMI is " + str(BMI) + ".")

if BMI < 16.5:
    print("You are underweight.") 
elif BMI < 25:
    print("You are normal.") 
elif BMI < 30:
    print("You are overweight.") 
else:
    print("You are obese.") 
