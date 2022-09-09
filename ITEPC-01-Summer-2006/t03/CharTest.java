/***************************************************************
Example 1 on Tutorial 3 (Java Basics).
Demostrate: char & string
****************************************************************/


import javax.microedition.midlet.*;

public class CharTest extends MIDlet
{
	// Constructor. You could igonre it first.
	public CharTest() { }

	// A required method (Start Application). Consider this function first.
	public void startApp()
	{
		// Double quota for string
		String h = "Hello ";

		// Sinlge quota for character
		char a = 'A';

		int x = 123;

		// "+" is used for striing concatenation. here
		// If one of operand is not a string, It would convert automatically.
		String h1 = h + a;
		String h2 = h + x;

		// We cannot write: String h3 = x;
		String h3 = String.valueOf(x);

		System.out.println(h1);
		System.out.println(h2);

		// We cannot have: System.out.println(x);
		System.out.println(h3);
	}

	// A required method (Pause Application). You could ignore it first.
	public void pauseApp()  { }

	// A required method (Destory Application). You could igonre it first.
	public void destroyApp(boolean unconditional)  { }
}
