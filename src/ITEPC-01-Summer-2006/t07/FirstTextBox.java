/***************************************************************
Example 1 on Topic 7 (Midlet and GameConvas 1).
Demostrate: A simple program to display text box.
****************************************************************/

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;

public class FirstTextBox extends MIDlet implements CommandListener
{
  // Initialize the Midlet Display variable
  private Display midletDisplay;

  // Initialize a variable for the cmdExit
  private Command cmdExit;

  public FirstTextBox()
  {
    // Retrieve the display from the static display object
    midletDisplay = Display.getDisplay(this);

	// Initialize the cmdExit
    cmdExit = new Command("Exit", Command.EXIT, 1);
  }

  /*
  * Create the first TextBox and associate
  * the exit command and listener.
  */
  public void startApp()
  {
    // Create the TextBox containing the "Hello,World!" message
    TextBox textBox = new TextBox("First Text Box Midlet", "This is my first text box!", 256, TextField.ANY);

    // Add the Exit Command to the TextBox
    textBox.addCommand(cmdExit);

    // Set the command listener for the textbox to the current midlet
    textBox.setCommandListener(this);

    // Set the current display of the midlet to the textBox screen
    midletDisplay.setCurrent(textBox);
  }

  /*
  * PauseApp is used to suspend background activities and release
  * resources on the device when the midlet is not active.
  */
  public void pauseApp()
  {
  }

  /*
  * DestroyApp is used to stop background activities and release
  * resources on the device when the midlet is at the end of its
  * life cycle.
  */
  public void destroyApp(boolean unconditional)
  {
  }

  /*
  * The commandAction method is implemented by this midlet to
  * satisfy the CommandListener interface and handle the Exit action.
  */
  public void commandAction(Command command, Displayable screen)
  {
    // If the command is the cmdExit
    if(command==cmdExit)
    {
      // Call the destroyApp method
      destroyApp(false);

      // Notify the midlet platform that the midlet has completed
      notifyDestroyed();
    }
  }
}

