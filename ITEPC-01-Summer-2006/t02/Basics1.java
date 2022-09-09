/***************************************************************
Example 1 on Tutorial 2 (Basics).
Demostrate: Printing out something to console.
****************************************************************/

import javax.microedition.midlet.*;

public class Basics1 extends MIDlet
{
	// Constructor. You could igonre it first.
	public Basics1() { }

	// A required method (Start Application). Consider this function first.
	public void startApp()
	{
		 // Print out the string "Hello World" to console.
		System.out.println("Hello World!");
	}

	// A required method (Pause Application). You could ignore it first.
	public void pauseApp()  { }

	// A required method (Destory Application). You could igonre it first.
	public void destroyApp(boolean unconditional)  { }
}
