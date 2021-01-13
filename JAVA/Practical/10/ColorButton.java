import java.util.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/*
	<applet code=ColorButton width=500 height=500></applet>
*/

//This class extends Applet class and implements ActionListener Interface
//that has actionPerferomed() method whic will be used to detect the event of button click
public class ColorButton extends Applet implements ActionListener{
	
	//creating Button Refrences
	Button Red;
	Button Blue;
	
	//init() method
	public void init()
	{
		//creating Button Objects
		Red = new Button("RED");
		Blue = new Button("BLUE");
		
		//using add() method of Component Class to add Button Objects to Layout
		add(Red);
		add(Blue);
		
		//changing button background
		Red.setBackground(Color.RED);
		Blue.setBackground(Color.BLUE);
		
		//adding ActionListener to the button
		Red.addActionListener(this);
		Blue.addActionListener(this);
	}
	
	//actionPerformed() method
	public void actionPerformed(ActionEvent a)
	{
		//string to obtain the label value of the button
		String s = a.getActionCommand();
		if(s == "RED")
		{
			setBackground(Color.RED);
		}
		else if(s == "BLUE")
		{
			setBackground(Color.BLUE);
		}
		
		repaint();
	}
	
	
}