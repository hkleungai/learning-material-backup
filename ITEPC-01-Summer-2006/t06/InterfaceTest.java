/***************************************************************
Example 2 on Tutorial 6 (Inheritance and Interface).
Demostrate: Interface
****************************************************************/


import javax.microedition.midlet.*;

interface MyComparable {
	public int compareTo(Object otherObject);
}

class Student implements MyComparable // Comparable
{
	// Constructor
	public Student(String _name, int  _chiMark, int _engMark, int _mathMark) {
		name = _name;
		chiMark = _chiMark;
		engMark = _engMark;
		mathMark = _mathMark;
		numOfStudent++;
	}

	public int compareTo(Object otherObject) {
		Student other = (Student) otherObject;
		int thisAverage = average();
		int otherAverage = other.average();
		if (thisAverage < otherAverage) return -1;
		if (thisAverage > otherAverage) return 1;
		return 0;
	}

	// Member functions
	public int getChiMark() {
		return chiMark;
	}

	public int getEngMark() {
		return engMark;
	}

	public int getMathMark() {
		return mathMark;
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

	// Member variables
	private String name;
	private int chiMark;
	private int engMark;
	private int mathMark;

	public static int numOfStudent=0;
}

public class InterfaceTest extends MIDlet
{
	public InterfaceTest() { }

	public void startApp() {

		Student calvin = new Student("Calvin",71,65,80);
		Student simon = new Student("Simon",72,66,81);

		if (simon.compareTo(calvin)==1) {
			System.out.println("Simon has a higher average mark.");
		}
	}

	public void pauseApp()  { }
	public void destroyApp(boolean unconditional)  { }
}
