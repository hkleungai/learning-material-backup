/***************************************************************
Example 1 on Tutorial 6 (Inheritance and Interface).
Demostrate: Inheritance
****************************************************************/


import javax.microedition.midlet.*;

class Student // Define a class called Student
{
	// Constructor
	public Student(String _name, int  _chiMark, int _engMark, int _mathMark) {
		name = _name;
		chiMark = _chiMark;
		engMark = _engMark;
		mathMark = _mathMark;
		numOfStudent++;
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

class CompStudent extends Student // A student which have take Computer Studies
{
	// Constructor
	public CompStudent(String _name, int  _chiMark, int _engMark, int _mathMark, int _compMark) {
		super(_name, _chiMark, _engMark, _mathMark);
		compMark = _compMark;
	}

	// Member functions
	public int getCompMark() {
			return compMark;
	}

	public int average() {
		int ave = (getChiMark() + getEngMark() + getMathMark() + compMark) / 4;
		return ave;
	}

	// Member variables
	private int compMark;
}


public class InheritanceTest extends MIDlet
{
	public InheritanceTest() { }

	public void startApp() {

		CompStudent calvin = new CompStudent("Calvin",71,65,80,90);
		Student simon = new Student("Simon",72,66,81);

		calvin.printAve();
		simon.printAve();
	}

	public void pauseApp()  { }
	public void destroyApp(boolean unconditional)  { }
}
