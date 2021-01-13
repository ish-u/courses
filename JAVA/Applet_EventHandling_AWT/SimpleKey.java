import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;


/*
	<applet code="SimpleKey" width="250" height="250"></applet>
*/


public class SimpleKey extends Applet implements KeyListener
{
	String msg = "";
	
	public void init()
	{
		addKeyListener(this);
	}
	
	public void keyPressed(KeyEvent k)
	{
		showStatus("key pressed");
		if(k.getKeyCode() == KeyEvent.VK_BACK_SPACE)
		{
			try
			{
				msg = msg.substring(0,msg.length()-1);
			}
			catch(IndexOutOfBoundsException e)
			{
				msg = "";
			}
			
		}
		else
		{
			msg += k.getKeyChar();
			repaint();
		}
		
	}
	
	public void keyReleased(KeyEvent k)
	{
		showStatus("key released");
		
	}
	
	public void keyTyped(KeyEvent k)
	{
		repaint();
		showStatus("key Typed");
	}
	
	public void paint(Graphics g)
	{
		g.drawString(msg,10,20);
	}
	
}