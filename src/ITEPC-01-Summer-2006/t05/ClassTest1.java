/***************************************************************
Example 1 on Tutorial 5 (Classes and Objects).
Demostrate: simple class definition
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
}


public class ClassTest1 extends MIDlet // A class called ClassTest1
{
	public ClassTest1() { }

	public void startApp() {
		Student calvin = new Student();
		calvin.setName("Calvin");
		calvin.setChiMark(71);
		calvin.setEngMark(65);
		calvin.setMathMark(80);

		Student simon = new Student();
		simon.setName("Simon");
		simon.setChiMark(72);
		simon.setEngMark(66);
		simon.setMathMark(81);

		calvin.printAve();
		simon.printAve();
	}

	public void pauseApp()  { }
	public void destroyApp(boolean unconditional)  { }
}
