/***************************************************************
Example 4 on Tutorial 2 (Basics).
Demostrate: while loop, do-while loop & for loop
****************************************************************/


import javax.microedition.midlet.*;

public class Basics4 extends MIDlet
{
	// Constructor. You could igonre it first.
	public Basics4() { }

	// A required method (Start Application). Consider this function first.
	public void startApp()
	{
		// While loop
		int i = 2;
		while (i < 100) {
			System.out.print(i + " ");
			i = i * 2;
		}
		System.out.println();

		// Do-while loop
		i = 1;
		do {
			i = i * 2;
			System.out.print(i + " ");
		} while (i < 100);
		System.out.println();

		// For loop
		for (i=0; i<10; i++) {
			System.out.print(i + " ");
		}
		System.out.println();
	}

	// A required method (Pause Application). You could ignore it first.
	public void pauseApp()  { }

	// A required method (Destory Application). You could igonre it first.
	public void destroyApp(boolean unconditional)  { }
}
