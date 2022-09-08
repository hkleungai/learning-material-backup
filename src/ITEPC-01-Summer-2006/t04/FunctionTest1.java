/***************************************************************
Example 1 on Tutorial 4 (Functions).
Demostrate: simple functions
****************************************************************/


import javax.microedition.midlet.*;

public class FunctionTest1 extends MIDlet
{
	// Constructor. You could igonre it first.
	public FunctionTest1() { }

	// An integer function
	int sum(int x, int y) {
		int z = x+y;
		return z;
	}

	// A boolean function
	boolean  isEven(int x) {
		boolean even = ( x % 2==0);
		return even;
	}

	// A "void" function (function with no return)
	void swapFail(int x, int y) {
		int temp = x;
		x = y;
		y = temp;
	}

	// A required method (Start Application)
	public void startApp() {
		int a = 3;
		int b = 4;
		int c = sum(a, b);

		System.out.println("c= " + c);

		if (isEven(b)) {
			System.out.println("b is an even number!");
		}

		System.out.println("Before calling swapFail(...):");
		System.out.println("a= " + a + ", b=" + b);

		swapFail(a, b);

		System.out.println("After calling swapFail(...):");
		System.out.println("a= " + a + ", b=" + b);
	}

	// A required method (Pause Application). You could ignore it first.
	public void pauseApp()  { }

	// A required method (Destory Application). You could igonre it first.
	public void destroyApp(boolean unconditional)  { }
}
