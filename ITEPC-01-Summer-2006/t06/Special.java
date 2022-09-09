/***************************************************************
Example 3 on Tutorial 6 (Inheritance and Interface).
Demostrate: Some special syntax
****************************************************************/


import javax.microedition.midlet.*;

public class Special extends MIDlet
{
	public Special() { }

	public void startApp() {

		int remainder;
		for(int i=0; i<10; i++) {
			System.out.println(i+" is divided by 4.");
			remainder = i%4;
			switch(remainder) {
				case 0:	System.out.println("The remainder is 0."); break;
				case 1:	System.out.println("The remainder is 1."); break;
				case 2:	System.out.println("The remainder is 2."); break;
				default:	System.out.println("The remainder is 3.");
			}

			String s=(remainder==0)?"Divisible!":"Not divisible!" ;
			System.out.println(s);
		}
	}

	public void pauseApp()  { }
	public void destroyApp(boolean unconditional)  { }
}