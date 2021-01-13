//SimpleKey Implementaion using Adapter Class 

import java.awt.event.*;
import java.awt.*;
import java.applet.*;

/*
	<applet width=400 height=400 code=AdapterDemo></applet>
*/

public class AdapterDemo extends Applet {

	public String msg = "";
	public void init()
	{
		addKeyListener(new MyKeyAdapter(this));
	}
	
	public void paint(Graphics g)
	{
		g.drawString(msg,30,30);
	}
}

class MyKeyAdapter extends KeyAdapter{
	
	AdapterDemo demo;
	public MyKeyAdapter(AdapterDemo demo)
	{
		this.demo = demo;
	}
	
	public void keyPressed(KeyEvent k)
	{
		demo.showStatus("KEY PRESSED");

		if(k.getKeyCode() == KeyEvent.VK_BACK_SPACE)
		{
			try
			{
				demo.msg = demo.msg.substring(0,demo.msg.length()-1);
			}
			catch(IndexOutOfBoundsException e)
			{
				demo.msg = "";
			}
			
		}
		else
		{
			demo.msg += k.getKeyChar();
			demo.repaint();
		}
		
	}
	
	public void keyTyped(KeyEvent k)
	{
		demo.showStatus("KEY TYPED");
		demo.repaint();
	}
}
