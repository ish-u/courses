import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

//JPanel class
class panel extends JPanel{
  //variables for the cursor and inset to find the location of JPanel
  Insets in;
  int x;
  int y;
  char flag;
  //repaint() method
  protected void paintComponent(Graphics g)
  {
    super.paintComponent(g);
    in = getInsets();
    y = in.top + 10;
    //flag variable determines which information needs to be displayed
		if(flag == 'A')
		{
			nextLine("Name : Anmol Gupta",g);
			nextLine("Course : BSc.(H) Computer Science",g);
			nextLine("Roll No. - 19/78009",g);
			nextLine("College - ARSD",g);

		}
		else if(flag == 'B')
		{
			nextLine("SCGPA : 9.09",g);

		}
  }
  //nextLine() method
  public void nextLine(String s, Graphics g)
  {
    x = in.left + 10;
    FontMetrics fm = g.getFontMetrics();
    y = y + fm.getHeight();
    g.drawString(s,x,y);

  }
}

//infoSwing class
public class infoSwing implements ActionListener{
  //creating Jbutton,JFrame and JPanel objects
  JButton A;
  JButton B;
  JFrame frame;
  panel panelButton;
  panel panelInfo;
  //constructor
  infoSwing()
  {
    //buttons
    A = new JButton("A");
    B = new JButton("B");
    //frame
    frame = new JFrame("Information");
    frame.setSize(500,500);
    frame.setLayout(null);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(true);
    //panel
    panelInfo = new panel();
    panelButton = new panel();
    panelButton.setBounds(180,10,100,50);
    panelInfo.setBounds(50,50,400,300);
    Font f = new Font("SansSerif",Font.PLAIN, 20);
    panelInfo.setFont(f);
    //adding components
    panelButton.add(A);
    panelButton.add(B);
    frame.add(panelButton);
    frame.add(panelInfo);
    A.addActionListener(this);
    B.addActionListener(this);

  }
  //event handling
  public void actionPerformed(ActionEvent e){
    if(e.getActionCommand() == "A")
    {
      panelInfo.flag = 'A';
      panelInfo.repaint();

    }
    else if(e.getActionCommand() == "B")
    {
      panelInfo.flag = 'B';
      panelInfo.repaint();
    }
  }
  //main() method
  public static void main(String args[])
  {
    SwingUtilities.invokeLater(new Runnable(){
      public void run(){
        new infoSwing();
      }
    });
  }


}
