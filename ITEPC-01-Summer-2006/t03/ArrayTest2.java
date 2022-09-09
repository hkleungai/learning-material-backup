/***************************************************************
Example 3 on Tutorial 3 (Java Basics).
Demostrate: multi dimensional Array
****************************************************************/


import javax.microedition.midlet.*;

public class ArrayTest2 extends MIDlet
{
	// Constructor. You could igonre it first.
	public ArrayTest2() { }

	// A required method (Start Application). Consider this function first.
	public void startApp()
	{
		int i, j;

		int [ ][ ] a;
		a = new int[3][ ];

		for (i=0; i<3; i++) {
			a[i] = new int[4];
		}

		int [ ][ ] b = new int[3][4];

		for (i=0; i<3; i++) {
			for (j=0; j<4; j++) {
				a[i][j] = i*4 + j;
				b[i][j] = j*3 + i;
			}
		}

		for (i=0; i<3; i++) {
			for (j=0; j<4; j++) {
				System.out.print(a[i][j] + "\t");
			}
			System.out.println();
		}

		System.out.print("\n\n");

		for (i=0; i<3; i++) {
			for (j=0; j<4; j++) {
				System.out.print(b[i][j] + "\t");
			}
			System.out.println();
		}
	}

	// A required method (Pause Application). You could ignore it first.
	public void pauseApp()  { }

	// A required method (Destory Application). You could igonre it first.
	public void destroyApp(boolean unconditional)  { }
}
