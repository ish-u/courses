import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class frameColorSwing
{
  //creating JFrame and JLabel refrence variables
  JFrame frame;
  JLabel label;

  //constructor
  frameColorSwing()
  {
    //initializing frame
    frame = new JFrame("COLOR STRING");
    frame.setSize(500,500);
    frame.setLayout(new FlowLayout());
    //NEED TO KNOW WHY I CAN"T DIRECTLY USE frame.setBackground() method here
    frame.getContentPane().setBackground(Color.PINK);
    frame.setVisible(true);

    //making the close button on the frame to end close Application
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    //initializing label
    label = new JLabel("This is a Test String. Background is Pink");
    frame.add(label);
  }

  //main() method
  public static void main(String[] args) {
    SwingUtilities.invokeLater(new Runnable(){
      public void run(){
        new frameColorSwing();
      }
    });
  }
}
