import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
	<applet width = 800 height = 800 code=resizeShapes></applet>
*/

public class resizeShapes extends Applet{
	
	final int inc = 25;
	int lenR = 300;
	int lenC = 500;
	
	public void init()
	{
		addMouseListener(new MyMouseAdapter(this));
	}
	
	public void paint(Graphics g)
	{
		g.drawRect(50,50,lenR,lenR);
		g.drawOval(50,50,lenC,lenC);
	}
}

class MyMouseAdapter extends MouseAdapter{
	
	resizeShapes s;
	MyMouseAdapter(resizeShapes s)
	{
		this.s = s;
	}
	
	//mouseClicked() method
	public void mouseClicked(MouseEvent m)
	{
		s.lenR = s.lenR < 500 ? s.lenR+s.inc : 300;
		s.lenC = s.lenC > 300 ? s.lenC-s.inc : 500;
		s.repaint();
	}
}