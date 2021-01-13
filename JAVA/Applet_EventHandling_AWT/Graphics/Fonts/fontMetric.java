import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.util.*;

/*
	<applet code=fontMetric width=500 height=500></applet>
*/

public class fontMetric extends Applet{

	int x = 0;
	int y = 0;
	
	public void init()
	{
		Font f = new Font("SansSerif", Font.BOLD, 16);
		setFont(f);
	}
	
	public void paint(Graphics g)
	{
		nextLine("LMAO",g);
		nextLine("LOL",g);
		nextLine("LOL",g);
		sameLine("LMAO",g);
		sameLine("LOL",g);
		
	}
	
	public void nextLine(String s, Graphics g)
	{
		FontMetrics fm = g.getFontMetrics();
		y += fm.getHeight();
		x = 0;
		g.drawString(s,x,y);
		x = fm.stringWidth(s);
	}
	
	public void sameLine(String s, Graphics g)
	{
		FontMetrics fm = g.getFontMetrics();
		g.drawString(s,x,y);
		x += fm.stringWidth(s);
	}
}