/***************************************************************
Example 3 on Topic 8 (Java Basics).
Demostrate: A program to show how to read key
****************************************************************/

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
import javax.microedition.lcdui.game.*;

class KeyCanvas extends GameCanvas{

    private MIDlet midlet;
    private String message;

    public KeyCanvas( MIDlet midlet ){
		super(false);
        this.midlet = midlet;
        message="Press a key";
    }

	public void keyPressed(int keyCode) {

		message="";

		switch(keyCode) {
			case KEY_NUM1:	message+="Key 1 is pressed. "; break;
			case KEY_NUM2:	message+="Key 2 is pressed. "; break;
			case KEY_NUM3:	message+="Key 3 is pressed. "; break;
			case KEY_NUM4:	message+="Key 4 is pressed. "; break;
			case KEY_NUM5:	message+="Key 5 is pressed. "; break;
			case KEY_NUM6:	message+="Key 6 is pressed. "; break;
			case KEY_NUM7:	message+="Key 7 is pressed. "; break;
			case KEY_NUM8:	message+="Key 8 is pressed. "; break;
			case KEY_NUM9:	message+="Key 9 is pressed. "; break;
		}

		switch(getGameAction(keyCode)) {
			case Canvas.FIRE:	message+="Key \"FIRE\" is pressed. "; break;
			case Canvas.UP:	message+="Key \"UP\"  is pressed. "; break;
			case Canvas.DOWN:	message+="Key \"Down\" is pressed. "; break;
		 	case Canvas.RIGHT:	message+="Key \"Right\"  is pressed. "; break;
			case Canvas.LEFT:	message+="Key \"LEFT\"  is pressed. "; break;
		}
		repaint();
	}

    public  void paint(Graphics g ) {
        g.setColor( 255, 255, 255 );
        g.fillRect( 0, 0, getWidth(), getHeight() );
        g.setColor( 0, 0, 0 );
        g.drawString( message, getWidth()/2, getHeight()/2, g.TOP | g.HCENTER );
    }
}


public class KeyEvent extends MIDlet {
    Display display;
    KeyCanvas canvas;

    public KeyEvent() {
        display = Display.getDisplay(this);
        canvas  = new KeyCanvas( this );
    }

    public void destroyApp (boolean unconditional) {
    }

    public void pauseApp () {
    }

    public void startApp () {
		display.setCurrent( canvas );
    }
}