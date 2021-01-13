import java.awt.*;
import java.awt.event.*;
import java.applet.*;


/*

	<applet code="MouseEvents" width=480 height=640></applet>
	
*/

public class MouseEvents extends Applet implements MouseListener
{

	String msg = "CLICKED";

	public void init()
	{
		addMouseListener(this);
		//addMouseMotionListener(this);
	}
	
	public void mouseClicked(MouseEvent m)
	{
		showStatus("clicked");
	}
	
	public void mouseEntered(MouseEvent m)
	{
		showStatus("entered");
	}
	public void mouseExited(MouseEvent m)
	{
		showStatus("exited");
	}
	public void mousePressed(MouseEvent m)
	{
		showStatus("pressed");
	}
	public void mouseReleased(MouseEvent m)
	{
		showStatus("released");
	}
	
	public void paint(Graphics g)
	{
		g.drawString(msg,50,50);
	}
}