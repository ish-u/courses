import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class mouseSwing
{
    JFrame frame;
    JLabel label;
    //constructor
    mouseSwing()
    {
      //creating JFrame
      frame = new JFrame("MOUSE EVENTS");
      frame.setSize(300,300);
      frame.setVisible(true);
      frame.setLayout(new FlowLayout());

      //making the close button on the frame to end close Application
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      //creating Label
      label = new JLabel("MOVE MOUSE");
      frame.add(label);

      //event handling
      frame.addMouseListener(new MyMouseAdapter(this));
    }

    //main() method to create frame
    public static void main(String args[])
    {
      SwingUtilities.invokeLater(new Runnable(){
        public void run(){
          new mouseSwing();
        }
      });
    }
}

//this class extends MouseAdapter Adapter Class of MouseListener interface
class MyMouseAdapter extends MouseAdapter
{
  mouseSwing m;
  MyMouseAdapter(mouseSwing m){
    this.m = m;
  }

  //mouseEntered() method
  public void mouseEntered(MouseEvent e)
  {
    m.frame.setSize(m.frame.getHeight()*3,m.frame.getWidth()*3);
    m.label.setText("MOUSE ENTERED");
  }

  //mouseExited() method
  public void mouseExited(MouseEvent e)
  {
    m.label.setText("MOUSE EXITED");
    System.exit(0);
  }

  //mouseClicked() method
  public void mouseClicked(MouseEvent e)
  {
    m.frame.setSize(300,300);
    m.label.setText("MOUSE CLICKED : (" + e.getX() + "," + e.getY() + ")");
  }

}
