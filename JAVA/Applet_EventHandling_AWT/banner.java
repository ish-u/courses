	/*
		<applet code=banner width=400 height=400>
			<param name="message" value = "LOL LMAO LOL LMAO">
		</applet>
	*/

import java.awt.*;
import java.applet.*;

public class banner extends Applet implements Runnable
{
	String msg = "A Sample SCROLL";
	Thread t = null;
	int state;
	volatile boolean stopFlag;
	Font f1;

	public void init()
	{
		setBackground(Color.red);
		setForeground(Color.black);
		f1 = new Font("Arial",Font.BOLD,18);
	}
	
	
	//Starting thread
	public void start()
	{
		t = new Thread(this);
		msg = "   " + getParameter("message");
		stopFlag = false;
		t.start();
	}
	
	public void run()
	{
		while(true)
		{
			try
			{
				repaint();
				Thread.sleep(1000);
				if(stopFlag)
				{
					break;
				}
			}
			catch(InterruptedException e){}
		}
	}
	
	public void stop()
	{
		stopFlag = true;
		t = null;
	}
	
	public void paint(Graphics g)
	{
		char ch;
		
		ch = msg.charAt(0);
		msg = msg.substring(1,msg.length());
		msg += ch;
		
		showStatus("LOL");
		g.setFont(f1);
		g.drawString(msg,50,50);
	}
}