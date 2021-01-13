import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*
  <applet code=colorButtonSwing height=500 width=500></applet>
*/

public class colorButtonSwing extends JApplet{

  //creating buttons and a label
  JButton Red;
  JButton Green;
  JLabel label;

  //init() method
  public void init()
  {
    try
    {
      SwingUtilities.invokeAndWait(new Runnable(){
        public void run()
        {
          makeGUI();
        }
      });
    }
    catch(Exception e)
    {
      System.out.print("Caught : " + e);
    }
  }

  private void makeGUI()
  {
    //setting layout to FLowLayout
    setLayout(new FlowLayout());

    //initialising buttons and label
    Red = new JButton("Red");
    Green = new JButton("Green");
    label = new JLabel("BACKGROUND COLOR");

    //event handling
    //using pseudoclasses
    Red.addActionListener(new ActionListener(){
      public void actionPerformed(ActionEvent a)
      {
        getContentPane().setBackground(Color.RED);
        label.setText("RED");
      }
    });

    Green.addActionListener(new ActionListener(){
      public void actionPerformed(ActionEvent a)
      {
        getContentPane().setBackground(Color.GREEN);
        label.setText("GREEN");
      }
    });

    //adding buttons and label to Container
    add(Red);
    add(Green);
    add(label);

  }
}
