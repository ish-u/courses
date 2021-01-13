import java.awt.event.*;
import java.awt.*;
import java.applet.*;
import java.util.*;

/*
	<applet code=SimpleKey height=500 width=500></applet>
*/

public class SimpleKey extends Applet{
	
	int next = 0;
	Font f;
	String msg = "";
	
	public void init()
	{
		//initailizing  a font
		f = new Font("Dailog", Font.BOLD , 16);
		showStatus("DAILOG");
		setFont(f);
		//adding Mouse And Keyboard event Listener
		addMouseListener(new MyMouseAdapter(this));
		addKeyListener(new MyKeyboardAdapter(this));
		
	}
	
	public void paint(Graphics g)
	{
		g.drawString(msg,10,10);
	}
}

//MouseEvents Adapter Class
class MyMouseAdapter extends MouseAdapter
{
	SimpleKey s;
	MyMouseAdapter(SimpleKey s)
	{
		this.s = s;
	}
	
	public void mouseClicked(MouseEvent m)
	{
		s.next++;
		switch(s.next)
		{
			case 0:
				s.f = new Font("Dailog", Font.BOLD , 16);
				s.showStatus("DAILOG");
				break;
				
			case 1:
				s.f = new Font("Serif", Font.BOLD,12);
				s.showStatus("Serif");
				break;
				
			case 2:
				s.f = new Font("DailogInput", Font.PLAIN, 13);
				s.showStatus("DailogInput");
				break;
				
			case 3:
				s.f = new Font("SansSerif", Font.ITALIC | Font.BOLD, 18);
				s.showStatus("SansSerif");
				break;
			
			case 4:
				s.f = new Font("Monospaced", Font.ITALIC, 24);
				s.showStatus("Monospaced");
				break;
		}
		
		if(s.next == 4)
		{
			s.next = -1;
		}
		
		s.setFont(s.f);
		s.repaint();
	}
}

//KeyBoardListener Adapter Class
class MyKeyboardAdapter extends KeyAdapter
{
	SimpleKey s;
	MyKeyboardAdapter(SimpleKey s)
	{
		this.s = s;
	}
	
	//keyPressed() method
	public void keyPressed(KeyEvent k)
	{
		if(k.getKeyCode() == KeyEvent.VK_BACK_SPACE)
		{
			try
			{
				s.msg = s.msg.substring(0,s.msg.length() - 1);
			}
			catch(IndexOutOfBoundsException e)
			{
				s.msg = "";
			}
		}
		else
		{
			s.msg += k.getKeyChar();
			s.repaint();
		}
	}
	
	//keyTyped() method
	public void keyTyped(KeyEvent k)
	{
		s.repaint();
		
	}
	
}