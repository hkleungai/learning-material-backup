/***************************************************************
Example 2 on Tutorial 3 (Java Basics).
Demostrate: one dimensional Array
****************************************************************/


import javax.microedition.midlet.*;

public class ArrayTest extends MIDlet
{
	// Constructor. You could igonre it first.
	public ArrayTest() { }

	// A required method (Start Application). Consider this function first.
	public void startApp()
	{
		int intArray1[ ]; // Method 1 to declare an array
		boolean [ ] boolArray; // Method 2 to declare an array

		intArray1 = new int[3];  // Allocate space for the array
		boolArray = new boolean[3]; // Allocate space for the array
		int [ ] intArray2 = new int[4]; // Declare and allocate space at the same line

		// Initialize values for intArray1
		intArray1[0] = 1;
		intArray1[1] = 3;
		intArray1[2] = 5;

		// Initialize values for boolArray
		boolArray[0] = true;
		boolArray[1] = false;
		boolArray[2] = true;

		// Initialize values for intArray2
		intArray2[0] = 2;
		intArray2[1] = 4;
		intArray2[2] = 6;

		int i;

		for (i=0; i<intArray1.length; i++) {
			intArray1[i] = intArray1[i] + intArray2[i];
		}

		for (i=0; i<intArray1.length; i++) {
			if (boolArray[i]) {
				System.out.println("intArray1[" + i + "] = " + intArray1[i] );
			}
		}
	}

	// A required method (Pause Application). You could ignore it first.
	public void pauseApp()  { }

	// A required method (Destory Application). You could igonre it first.
	public void destroyApp(boolean unconditional)  { }
}
