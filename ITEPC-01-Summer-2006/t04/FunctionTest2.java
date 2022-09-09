/***************************************************************
Example 2 on Tutorial 4 (Functions).
Demostrate: pass array to function
****************************************************************/


import javax.microedition.midlet.*;

public class FunctionTest2 extends MIDlet
{
	// Constructor. You could igonre it first.
	public FunctionTest2() { }

	// A function to swap two integer
	void swapInt(int[] x) {
		int temp = x[0];
		x[0] = x[1];
		x[1] = temp;
	}

	// A required method (Start Application).
	public void startApp() {
		int [ ] z = {3, 4};
		System.out.println("Before calling swapInt(...):");
		System.out.println("z[0]= " + z[0] + ", z[1]= " + z[1]);
		swapInt(z);
		System.out.println("After calling swapInt(...):");
		System.out.println("z[0]= " + z[0] + ", z[1]= " + z[1]);
	}

	// A required method (Pause Application). You could ignore it first.
	public void pauseApp()  { }

	// A required method (Destory Application). You could igonre it first.
	public void destroyApp(boolean unconditional)  { }
}
