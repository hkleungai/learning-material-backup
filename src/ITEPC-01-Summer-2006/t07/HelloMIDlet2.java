/***************************************************************
Example 4 on Topic 7 (Midlet and GameConvas 1).
Demostrate: A HelloWorld program using GameCanvas
                         with an "Exit" Command.
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

    public  void paint( Graphics g ){
        g.setColor( 255, 255, 255 );
        g.fillRect( 0, 0, getWidth(), getHeight() );
        g.setColor( 0, 0, 0 );
		g.drawString( "Hello,World!", getWidth()/2, 0,g.TOP | g.HCENTER );
    }
}

public class HelloMIDlet2 extends MIDlet implements CommandListener {
    private Display  display;
    private HelloCanvas canvas;
    private Command  exitCommand = new Command(
                          "Exit", Command.SCREEN, 1 );

    public HelloMIDlet2 (){
        display = Display.getDisplay( this );
        canvas  = new HelloCanvas( this );
        canvas.addCommand( exitCommand );
        canvas.setCommandListener( this );
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

    public void commandAction( Command c, Displayable d ){
	        if( c == exitCommand ){
	            exit();
	        }
    }
}
