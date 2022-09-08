/***************************************************************
Example 4 on Tutorial 5 (Classes and Objects).
Demostrate: Constructor
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

	// Member variables;
	private String name;
	private int chiMark;
	private int engMark;
	private int mathMark;

	public static int numOfStudent=0;
}


public class ClassTest4 extends MIDlet
{
	public ClassTest4() { }

	public void startApp() {

		Student calvin = new Student("Calvin",71,65,80);
		Student simon = new Student("Simon",72,66,81);
		Student desmond = new Student("Desmond",74,74,74);

		System.out.println("Calvin's marks: " + calvin.getChiMark() + ", " + calvin.getEngMark() + ", " + calvin.getMathMark() );
		System.out.println("Number of students: " + Student.getNumOfStudent());
		calvin.printAve();
		simon.printAve();
		desmond.printAve();
	}

	public void pauseApp()  { }
	public void destroyApp(boolean unconditional)  { }
}
