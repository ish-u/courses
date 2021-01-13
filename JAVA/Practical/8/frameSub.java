import java.awt.*;
import java.awt.event.*;
import java.applet.*;

//creating a subclass of Frame Class
public class frameSub extends Frame
{
	int mouseX = 0;
	int mouseY = 0;
	String msg = "" ;
	public frameSub()
	{
		super("MOUSE TEST");
		addWindowListener(new MyWindowsAdapter());	//using Adapter Class object to add to Listener
		addMouseListener(new MyMouseAdapter(this));		//using Adapter Class object to add to Listener
	}

	//paint method
	public void paint(Graphics g)
	{
		g.drawString(msg,mouseX,mouseY);
	}

	//using main() method to create a single frame rather tha using applet
	public static void main(String args[])
	{
		//creating a frame object i.e creating a frame or a window
		frameSub f = new frameSub();
		f.setSize(new Dimension(300,300));
		Font font = new Font("SansSerif",Font.BOLD,16);
		f.setFont(font);
		f.setVisible(true);
	}
}

//Adapter Class For MouseListener
class MyMouseAdapter extends MouseAdapter
{
	frameSub f;		//creating a Frame refrence variable
	MyMouseAdapter(frameSub f)
	{
		this.f = f;
	}

	//mouseClick() method
	public void mouseClicked(MouseEvent m)
	{
		f.msg = " Mouse Clicked (" + m.getX() + "," + m.getY() + ")";
		f.setSize(new Dimension(300,300));
		f.mouseX = m.getX();
		f.mouseY = m.getY();
		f.repaint();
	}

	//mouseEntered() method
	public void mouseEntered(MouseEvent m)
	{
		//f.setVisible(true);			//making frame visible on the entry of Mouse
		f.msg = " Mouse Entered ";
		f.setSize(f.getHeight()*3,f.getWidth()*3);	//making frame 3times the current dimension
		f.mouseX = f.getWidth()/3;
		f.mouseY = f.getHeight()/2;
		f.repaint();
	}

	//mouseExited() method
	public void mouseExited(MouseEvent m)
	{
		//f.setVisible(false);	//making frame invisible on exit of Mouse
		f.msg = " Mouse Exited ";
		f.mouseX = 250;
		f.mouseY = 250;
		f.repaint();
		System.out.print(f.msg);
		System.exit(0);				//exiting when mouse exits frame
	}
}

//Adapter Class for WindowsListner
class MyWindowsAdapter extends WindowAdapter{

	//windowClosing() method
	public void windowClosing(WindowEvent m)
	{
		System.exit(0);
	}

}
