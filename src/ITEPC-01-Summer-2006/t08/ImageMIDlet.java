/***************************************************************
Example 1 on Topic 8 (Java Basics).
Demostrate: A program to display an image
****************************************************************/

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
import javax.microedition.lcdui.game.*;

class ImageCanvas extends GameCanvas{

    private MIDlet midlet;
    private Image ustLogo;

    public ImageCanvas( MIDlet midlet ){
		super(false);
        this.midlet = midlet;
        try {
        	ustLogo = Image.createImage("/logo.png");
		} catch(Exception e) {
			ustLogo = null;
			System.out.println("File not found!");
		}
    }

    public  void paint( Graphics g ){
        g.setColor( 255, 255, 255 );
        g.fillRect( 0, 0, getWidth(), getHeight() );
        g.setColor( 0, 0, 0 );
		g.drawImage(ustLogo, getWidth()/2, getHeight()/2, g.VCENTER | g.HCENTER );
    }
}

public class ImageMIDlet extends MIDlet implements CommandListener {
    private Display  display;
    private ImageCanvas canvas;
    private Command  exitCommand = new Command(
                          "Exit", Command.SCREEN, 1 );

    public ImageMIDlet() {
        display = Display.getDisplay( this );
        canvas  = new ImageCanvas( this );
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
