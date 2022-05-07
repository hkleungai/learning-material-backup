import turtle
import random

def createTurtles():# This function creates 9 turtles
    global allTurtles
    
    for count in range(9): # Do it 9 times
        newTurtle = turtle.Turtle() # Make a new turtle
        newTurtle.shape("square") # It will look like a square
        newTurtle.shapesize(4, 4) # Make it bigger
        newTurtle.up() # Take the pen off the page, otherwise lines will be drawn
        newTurtle.speed(0) # This turtle can move as fast as possible, helpful for dragging
        newTurtle.goto(random.randint(-300, 300), random.randint(-300, 300)) # Move it to a random position
        newTurtle.ondrag(newTurtle.goto) # Make sure we can drag it around the screen
        allTurtles.append(newTurtle) # Add the new turtle to the new list of turtles

##############
## The following 2 functions do file handling:
##############
        
def savePositions(): # Save all the turtle positions
    filename = turtle.textinput("Save turtle positions", \
        "What is the filename you want to create?")
    myfile = open(filename, "wt") # Open the file for writing

    # Now we go through each turtle in the data structure
    for thisTurtle in allTurtles: 

        # Make a string for one turtle, in the right format
        one_line = str(thisTurtle.xcor()) + "\t" + str(thisTurtle.ycor()) + "\n"

        # Save the string to the file
        myfile.write(one_line)

    # Close the file
    myfile.close()
    turtle.listen() # Make sure any future key presses go to this program


def loadPositions(): # Load all the turtle positions, move the turtles
    global allTurtles
    
    filename = turtle.textinput("Load turtle positions", \
        "What is the filename you want to load?")
    myfile = open(filename, "r") # Open the file for reading
    turtleIndex=0
    for line in myfile: 
            # Read each line as a single rule
            line = line.rstrip()    # Remove the end-of-line character
            print("line is", line)

            items = line.split("\t")# Separate the two items
            print("line is", line)  # Line is now a list
                                    # containing two items
            x=float(items[0]) # Convert the x string to a float
            y=float(items[1]) # Convert the y string to a float
            print("x is", x, " y is", y) 
            
            allTurtles[turtleIndex].goto(x, y) # Restore the turtle position
            turtleIndex = turtleIndex+1 # Get ready for the next turtle
            
    # Close the file
    myfile.close()
    turtle.listen() # Make sure any future key presses go to this program


# Main part
allTurtles=[] # We will store all the turtles in this list
createTurtles() # Create the turtles
    
##############
## Key presses for the file handling:
turtle.onkeypress(savePositions, "s") # Save turtle positions
turtle.onkeypress(loadPositions, "l") # Load turtle positions
##############

turtle.listen() # Listen for any key presses
turtle.mainloop() # Keep checking if anything is happening, if so do something appropriate
