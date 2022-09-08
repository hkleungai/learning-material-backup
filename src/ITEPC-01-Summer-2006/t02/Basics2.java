/***************************************************************
Example 2 on Tutorial 2 (Basics).
Demostrate: int type and some basic operation for int
****************************************************************/


import javax.microedition.midlet.*;

public class Basics2 extends MIDlet
{
	// Constructor. You could igonre it first.
	public Basics2() { }

	// A required method (Start Application). Consider this function first.
	public void startApp()
	{
		 // Decare an integer x.
		int x;
		// Decare integers y and z at one line.
		int y, z;

		// Assign values for variables x, y and z
		x = 1;
		y = 3;
		z = 5;

		// Decare and assign value in the same line
		int a=7;

		// Print out values of varialbes x, y, z, a
		System.out.print("Values of x, y, z & a: ");
		System.out.println(x + " " + y + " " + z + " " + a);

		// Additon, Subtraction & Mutiplication
		int b = y + z;
		int c = z - y;
		System.out.print("Values of b, c & b*c: ");
		System.out.println(b + " " + c + " " + b*c);

		// Division
		b = a / y; // Quotient
		c = a % y; // Reminder
		System.out.print("Values of b & c: ");
		System.out.println(b + " " + c);
	}

	// A required method (Pause Application). You could ignore it first.
	public void pauseApp()  { }

	// A required method (Destory Application). You could igonre it first.
	public void destroyApp(boolean unconditional)  { }
}
