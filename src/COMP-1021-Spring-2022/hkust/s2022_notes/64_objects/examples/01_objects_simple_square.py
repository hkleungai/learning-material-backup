"""
This is an example of a simple class. This class represents a square. The class
has one attribute, the length of the side. It has two methods, the constructor
and a function to calculate the area of the square. When an instance of the
class is created it must be given the length of the side.

In this example we make an instance of the class, and then ask the instance
what area it has. Then we change the side length of the instance and ask it
again what area it has.
"""

class SimpleSquare:
    # This is the constructor of the object
    def __init__(self, length):
        # Initialize the attribute "length"
        self.length = length
        
    # This method returns the area of the square
    def area(self):
        return self.length * self.length

# Create a square and show the area
mysquare = SimpleSquare(50)
print("The area is", mysquare.area())

# Modify the length of the square and show the area
mysquare.length = 100
print("The area now is", mysquare.area())
