import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
	<applet height=500 width=500 code=GraphicsDemo></applet>
*/

public class GraphicsDemo extends Applet{
	
	public void paint(Graphics g)
	{
		//getting colors
		Color c1 = new Color(255,0,0);
		Color c2 = new Color(25,255,26);
		Color c3 = new Color(37,103,157);
		
		//lines
		g.setColor(c1);
		g.drawLine(50,30,250,250);
		g.drawLine(30,20,200,80);
		g.drawLine(1,1,500,500);
		
		//rectangle
		g.setColor(c2);
		g.drawRect(10,50,20,30);
		g.fillRect(60,70,20,30);
		
		//ellipse
		g.setColor(c3);
		g.drawOval(100,120,50,50);
		g.fillOval(100,300,60,60);
		
		//arcs
		g.drawArc(1,1,250,300,90,50);
		g.fillArc(170,375,10,10,45,45);
		
		//polygon
		int xpoint[] = {10,20,30,40,50};
		int ypoint[] = {275,45,85,63,451};
		int num = 5;
		
		g.drawPolygon(xpoint,ypoint,num);
	}
}