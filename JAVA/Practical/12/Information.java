import java.util.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/*
	<applet width=500 height=500 code=Information></applet>
*/

public class Information extends Applet implements ActionListener{
	
	//creating button object refrence
	Button A;
	Button B;
	
	//variables to keep track of cursor
	int x = 0;
	int y = 0;
	
	//variable to decide which information to show
	char c;
	
	//init() method
	public void init()
	{
		//craeting Button Objects
		A = new Button("A");
		B = new Button("B");
		
		//Adding Button Objects to the Layout
		add(A);
		add(B);
		
		//Adding event listener to the Button Object
		A.addActionListener(this);
		B.addActionListener(this);
		
		//Setting Font
		Font f = new Font("SansSerif", Font.PLAIN, 20);
		setFont(f);
		
	}
	
	//actionPerformed() method
	public void actionPerformed(ActionEvent a){
		
		if(a.getActionCommand() == "A")
		{
			c = 'A';
			repaint();
			
		}
		else if(a.getActionCommand() == "B")
		{
			c = 'B';
			repaint();
			
		}
		
		
	}
	
	
	//paint() method
	public void paint(Graphics g)
	{
		//moves the cursor back to (0,100)
		y = 100;
	
		//c variable determines which determines which information needs to be displayed
		if(c == 'A')
		{
			nextLine("Name : Anmol Gupta",g);
			nextLine("Course : BSc.(H) Computer Science",g);
			nextLine("Roll No. - 19/78009",g);
			nextLine("College - ARSD",g);
		
		}
		else if(c == 'B')
		{
			nextLine("SCGPA : 9.09",g);	
		
		}
	}
	
	//nextLine() method
	//this is used to move cursor to next line
	//each time this method is called the cursor is moved by FontHeight in the y direction 
	public void nextLine(String s,Graphics g)
	{
		FontMetrics fm = g.getFontMetrics();
		y = y+fm.getHeight();
		x = 50;
		g.drawString(s,x,y);
		
	}
	
}