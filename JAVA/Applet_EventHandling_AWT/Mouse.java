import java.awt.*;
import java.awt.event.*;
import java.applet.*;


/*

	<applet code="mouse" width=480 height=640></applet>
	
*/

public class MouseEvents extends Applet implements MouseEventListener,MouseMotionListener
{

	String msg = "CLICKED";

	public void init()
	{
		addMouseListener(this);
		addMouseMotionListener(this);
	}
	
	public void mouseClicked(MouseEvent m)
	{
		repaint();
	}
	
	public void paint(Graphics g)
	{
		g.drawString(msg,50,50);
	}
}