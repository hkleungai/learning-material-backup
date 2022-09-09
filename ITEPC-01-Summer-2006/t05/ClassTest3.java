/***************************************************************
Example 3 on Tutorial 5 (Classes and Objects).
Demostrate: public and private
****************************************************************/


import javax.microedition.midlet.*;

class Student // Define a class called Student
{
	// Member functions
	public void setName(String _name) {
		name = _name;
	}

	public void setChiMark(int _chiMark) {
		chiMark = _chiMark;
	}

	public int getChiMark() {
			return chiMark;
	}

	public void setEngMark(int _engMark) {
		engMark = _engMark;
	}

	public void setMathMark(int _mathMark) {
		mathMark = _mathMark;
	}

	public static int getNumOfStudent() {
		return numOfStudent;
	}

	public void printAve() {
		System.out.println(name + ": " + average() );
	}

	public int average() {
		int ave = (chiMark + engMark + mathMark) / 3;
		return ave;
	}

	// Member variables;
	private String name;
	private int chiMark;
	private int engMark;
	private int mathMark;

	public static int numOfStudent;;
}


public class ClassTest3 extends MIDlet
{
	public ClassTest3() { }

	public void startApp() {
		Student calvin = new Student();
		calvin.setName("Calvin");
		calvin.setChiMark(71);
		int chiMark = calvin.getChiMark();
		System.out.println("Chinese Mark: " + chiMark);
	}

	public void pauseApp()  { }
	public void destroyApp(boolean unconditional)  { }
}
