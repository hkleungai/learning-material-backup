/***************************************************************
Example 2 on Topic 7 (Midlet and GameConvas 1).
Demostrate: Using mutiple textboxes and command buttons.
****************************************************************/

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;

public class TextBoxMIDlet extends MIDlet  implements CommandListener {
    Display display;
    TextBox t1, t2, t3;
    Command prn, one, two, three;

    public void destroyApp (boolean unconditional) {}

    public void pauseApp () {}

    public void startApp () {
        display = Display.getDisplay(this);

		t1 = new TextBox("ANY", "", 50, TextField.ANY);

		 try {
				t2 = new TextBox("NUMERIC", "-123", 15, TextField.NUMERIC);
		 } catch (Exception  e) {
				System.out.println("no error");
		 }

		t3 = new TextBox("PHONE NUMBER", "", 8, TextField.PHONENUMBER);

        prn  = new Command("PRT", Command.BACK, 1);
        one  = new Command("ANY",  Command.EXIT, 10);
        two = new Command("NUMERIC",Command.EXIT, 20);
        three  = new Command("PHONE NUMBER", Command.EXIT, 30);

        t1.addCommand(prn);
        t1.addCommand(one);
        t1.addCommand(two);
        t1.addCommand(three);
        t1.setCommandListener(this);

        t2.addCommand(prn);
        t2.addCommand(one);
        t2.addCommand(two);
        t2.addCommand(three);
        t2.setCommandListener(this);

        t3.addCommand(prn);
        t3.addCommand(one);
        t3.addCommand(two);
        t3.addCommand(three);
        t3.setCommandListener(this);

        display.setCurrent(t1);
    }

	public void commandAction(Command x, Displayable s) {
		if (x == prn) {
			TextBox cur  = (TextBox)display.getCurrent();
			System.out.println(cur.getString());
		} else if (x == one) {
			display.setCurrent(t1);
		} else if (x == two) {
			display.setCurrent(t2);
		} else if (x == three) {
			display.setCurrent(t3);
		}
	}
}
