import java.util.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/*
	<applet width=500 height=500 code=KeyPress></applet>
*/

public class KeyPress extends Applet
{
	//string which will tell which key is pressed
	String msg = "";
	 
	//init() method
	public void init()
	{
		//adding source to listener
		addKeyListener(new MyKeyAdapter(this));
		//setting font
		Font f = new Font("SansSerif", Font.BOLD, 50);
		setFont(f); 
	}
	
	//paint() method
	public void paint(Graphics g)
	{
		//getting the dimension of applet
		Dimension d = this.getSize();
		//drawing a rectangle around the boundary of frame
		g.drawRect(0,0,d.width - 1, d.height - 1);
		//drawing string in the middle
		g.setColor(Color.BLACK);
		g.drawString(msg,d.width/2,d.height/2);
		
	}

}

//using AdapterClass of KeyListener to implement keyPressed() method
class MyKeyAdapter extends KeyAdapter{
	
	//creating an object refrence of KeyPress class
	KeyPress kp;
	MyKeyAdapter(KeyPress kp)
	{
		this.kp = kp;
	}
	
	//KeyPressed() method
	
	public void keyTyped(KeyEvent k)
	{
		kp.msg = "";
		kp.msg += k.getKeyChar();
		kp.showStatus("Typed Character is : " + k.getKeyChar());
		kp.repaint();
	}
} 