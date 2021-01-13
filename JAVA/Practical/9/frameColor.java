import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class frameColor extends Frame{

	//message to be displayed on the frame
	String msg = "this is a test string";
	
	//constructor
	frameColor()
	{
		super("COLOR FRAME EXAMPLE");				//Passing the title of the frame to the Frame Class constructor
		setBackground(Color.PINK);					//chaning the background color to PINK
		addWindowListener(new MyWindowAdapter());	//adding event listener to WindowEvent	
	}
	
	//paint() method
	public void paint(Graphics g)
	{
		g.drawString(msg,150,250);
	}
	
	//main() method
	//using main() method to run a single frame rather than using appletviewer 
	public static void main(String args[])
	{
		frameColor f = new frameColor();
		f.setVisible(true);
		f.setSize(new Dimension(500,500));
	}
}

//Adapter Class of WindowListener
class MyWindowAdapter extends WindowAdapter{
	public void windowClosing(WindowEvent w)
	{
		System.exit(0);
	}
}