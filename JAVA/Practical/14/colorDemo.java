import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class colorDemo extends JFrame
{
  JLabel label;
  colorDemo()
  {
    super("COLOR DEMO");
    setSize(500,500);
    setBackground(Color.PINK);
    setVisible(true);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    //Label
    label = new JLabel("This is a test");
    add(label);
  }

  public static void main(String args[])
  {
    SwingUtilities.invokeLater(new Runnable(){
      public void run()
      {
        new colorDemo();
      }
    });
  }
}
