	/*
		<applet code=app width=400 height=400></applet>
		
	*/

import java.awt.*;
import java.applet.*;

public class app extends Applet{

	String msg;
	
	public void init()
	{
		setBackground(Color.darkGray);
		setForeground(Color.black);
		msg = "Inside init()";
		
	}
	
	public void start()
	{
		msg += "Inside start()";
	}
	
	public void paint(Graphics g)
	{
		msg += "Inside paint()";
		g.drawString(msg,50,50);
	}
	
}