/***************************************************************
Example 3 on Tutorial 2 (Basics).
Demostrate: comparison operation, bool type and if-else statement
****************************************************************/


import javax.microedition.midlet.*;

public class Basics3 extends MIDlet
{
	// Constructor. You could igonre it first.
	public Basics3() { }

	// A required method (Start Application). Consider this function first.
	public void startApp()
	{
		int x=2;
		int y=1;

		if (x==y) {
			System.out.println("x equals to y!");
		}
		else {
			System.out.println("x doesn't equals to y!");
		}

		boolean t = true;
		boolean f = false;

		if (t && f) {
			System.out.println("Both t and f are true!");
		}

		if (t || f) {
			System.out.println("Either t or f are true!");
		}

		if (t && !f) {
			System.out.println("t is true and f is false!");
		}
	}

	// A required method (Pause Application). You could ignore it first.
	public void pauseApp()  { }

	// A required method (Destory Application). You could igonre it first.
	public void destroyApp(boolean unconditional)  { }
}
