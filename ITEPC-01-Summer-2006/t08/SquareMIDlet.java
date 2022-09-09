/***************************************************************
Example 2 on Topic 8 (Java Basics).
Demostrate: A program to display many squares
****************************************************************/

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
import javax.microedition.lcdui.game.*;

class SquareCanvas extends GameCanvas{

    private MIDlet midlet;

    private int bWidth;
    private int bHeight;

    private int numOfVBlock;
    private int numOfHBlock;

    private int vMargin;
    private int hMargin;

    public static final int BLK_SIZE=12;
    public static final int SPACE=2;
    public static final int MIN_MARGIN=4;

    public SquareCanvas( MIDlet midlet ){
		super(false);
        this.midlet = midlet;

		bWidth=getWidth();
        bHeight=getHeight();

		int hTemp=bWidth-SPACE-MIN_MARGIN;
		int vTemp=bHeight-SPACE-MIN_MARGIN;

		numOfHBlock = hTemp / (BLK_SIZE+SPACE);
		numOfVBlock= vTemp / (BLK_SIZE+SPACE);

		vMargin=(vTemp % (BLK_SIZE+SPACE) + MIN_MARGIN) / 2;
		hMargin=(hTemp % (BLK_SIZE+SPACE) + MIN_MARGIN) / 2;
    }

    public  void paint( Graphics g ){
		int posX, posY;
        g.setColor(255, 255, 255);
        g.fillRect( 0, 0, getWidth(), getHeight() );
		g.setColor(255, 0, 0);

		posY = SPACE + vMargin;
		 for(int i=0; i<numOfVBlock; i++) {
			posX = SPACE + hMargin;
			for(int j=0; j<numOfHBlock; j++) {
				g.fillRect(posX,posY,BLK_SIZE,BLK_SIZE);
				posX += BLK_SIZE+SPACE;
			}
			posY += BLK_SIZE+SPACE;
		}
	}
}

public class SquareMIDlet extends MIDlet implements CommandListener {
    private Display  display;
    private SquareCanvas canvas;
    private Command  exitCommand = new Command(
                          "Exit", Command.SCREEN, 1 );

    public SquareMIDlet() {
        display = Display.getDisplay( this );
        canvas  = new SquareCanvas( this );
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
