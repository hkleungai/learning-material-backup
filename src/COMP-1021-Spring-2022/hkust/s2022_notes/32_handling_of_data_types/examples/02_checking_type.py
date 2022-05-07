"""
This example demonstrates using the type() command to check the data type of
variables.
"""

def double(x):
    if type(x) == int or type(x) == float:
        print( 2 * x )
    else:
        print("Hey, give me a number!")

double("Hello!")
