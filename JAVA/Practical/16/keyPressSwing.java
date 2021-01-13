import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;


public class keyPressSwing{

  //creating JFrame and JLabel
  JFrame frame;
  JLabel label;

  //constructor
  keyPressSwing(){
    //initialising JFrame
    frame = new JFrame("KEYBOARD EVENTS");
    frame.setLayout(new FlowLayout());
    frame.setSize(500,500);
    frame.setVisible(true);
    Font f = new Font("SansSerif", Font.PLAIN, 40);
    //making the close button on the frame to end close Application
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.getContentPane().setFont(f);
    //initialising JLabel
    label = new JLabel("TYPE");
    //adding label to JFrame
    frame.add(label);
    //event handling in JFrame
    frame.addKeyListener(new MyKeyClass(this));
  }

  //main() method
  public static void main(String args[]){
    SwingUtilities.invokeLater(new Runnable(){
      public void run(){
        new keyPressSwing();
      }
    });
  }

}

//keyboard handling
class MyKeyClass extends KeyAdapter{
  //creating keyPressSwing object
  keyPressSwing k;
  //constructor
  MyKeyClass(keyPressSwing k)
  {
    this.k = k;
  }
  //keyTyped method()
  public void keyTyped(KeyEvent e)
  {
    k.label.setText("TYPED : " + e.getKeyChar());
  }
}
