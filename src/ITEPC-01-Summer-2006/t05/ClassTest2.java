/***************************************************************
Example 2 on Tutorial 5 (Classes and Objects).
Demostrate: static variables and functions
****************************************************************/


import javax.microedition.midlet.*;

class Student // Define a class called Student
{
	// Member functions
	void setName(String _name) {
		name = _name;
	}

	void setChiMark(int _chiMark) {
		chiMark = _chiMark;
	}

	void setEngMark(int _engMark) {
		engMark = _engMark;
	}

	void setMathMark(int _mathMark) {
		mathMark = _mathMark;
	}

	// Static function
	static int getNumOfStudent() {
		return numOfStudent;
	}

	void printAve() {
		System.out.println(name + ": " + average() );
	}

	int average() {
		int ave = (chiMark + engMark + mathMark) / 3;
		return ave;
	}

	// Member variables;
	String name;
	int chiMark;
	int engMark;
	int mathMark;

	// Static variable
	public static int numOfStudent;
}


public class ClassTest2 extends MIDlet
{
	public ClassTest2() { }

	public void startApp() {
		Student calvin = new Student();
		calvin.setName("Calvin");
		Student simon = new Student();
		simon.setName("Simon");
		Student desmond = new Student();
		desmond.setName("Desmond");

		calvin.printAve();
		simon.printAve();
		desmond.printAve();

		Student.numOfStudent = 3;
		int n= Student.getNumOfStudent();
		System.out.println("Number of students: " + n);
	}

	public void pauseApp()  { }
	public void destroyApp(boolean unconditional)  { }
}
