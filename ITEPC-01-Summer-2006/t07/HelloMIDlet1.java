/***************************************************************
Example 3 on Topic 7 (Midlet and GameConvas 1).
Demostrate: A HelloWorld program using GameCanvas
****************************************************************/

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
import javax.microedition.lcdui.game.*;

class HelloCanvas extends GameCanvas{

    private MIDlet midlet;

    public HelloCanvas( MIDlet midlet ){
		super(false);
        this.midlet = midlet;
    }

    public void paint(Graphics g){
        g.setColor( 255, 255, 255 ); // Set the colour as white
        g.fillRect( 0, 0, getWidth(), getHeight() ); // Fill the white colour to the whole screen
        g.setColor( 0, 0, 0 ); // Set the colour as black
		g.drawString( "Hello,World!", getWidth()/2, 0,g.TOP | g.HCENTER ); // Draw the black text
    }
}

public class HelloMIDlet1 extends MIDlet {
    private Display  display;
    private HelloCanvas canvas;

    public HelloMIDlet1 (){
        display = Display.getDisplay( this );
        canvas  = new HelloCanvas( this );
    }

    protected void startApp(){
        display.setCurrent( canvas );
    }

    protected void pauseApp(){}

    protected void destroyApp( boolean unconditional ){}

    public void exit(){
        destroyApp( true );
        notifyDestroyed();
    }
}