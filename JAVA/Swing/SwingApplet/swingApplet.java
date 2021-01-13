import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/*
  <applet width = 500 height = 500 code = swingApplet></applet>
*/

//we using Swing applet class JApplet which is inherited from Applet class
public class swingApplet extends JApplet
{
  //button
  JButton Red;
  JButton Green;

  //Label
  JLabel label;

  //init() method
  public void init()
  {
    //using makeGUI() method run the applet
    //using a thred (god knows what it is)
    try
    {
      SwingUtilities.invokeLater(new Runnable()
      {
        public void run()
        {
          makeGUI();
        }
      });
    }
    catch(Exception e)
    {
      System.out.print("CAUGHT Exception : "+ e);
    }

  }

  private void makeGUI()
  {
    //changing flow layout
    setLayout(new FlowLayout());

    //inittailsing button and Label
    Red = new JButton("RED");
    Green = new JButton("GREEN");
    label = new JLabel("click on any button to change me");

    //adding event handling
    Red.addActionListener(new ActionListener()
    {
      public void actionPerformed(ActionEvent a)
      {
        label.setText(a.getActionCommand());
      }
    }
    );

    Green.addActionListener(new ActionListener()
    {
      public void actionPerformed(ActionEvent a)
      {
        label.setText(a.getActionCommand());
      }
    }
    );

    //using pseudoclasses above
    //adding button to Content pane
    add(Red);
    add(Green);
    add(label);
  }
}
