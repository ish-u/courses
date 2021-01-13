//importing javax.swing packages

import javax.swing.*;

class swingDemo{

  //constructor
  swingDemo()
  {
    //creating frame
    JFrame jfrm = new JFrame("A Simple Swing Application");

    //creating Label Component
    JLabel label = new JLabel("This is some text centered on a JFrame of a Jlabel");

    //setting height and width
    jfrm.setSize(500,500);

    //close the Swing Application on clicking the cross('x') button on the JFrame
    jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    //adding the label to the content pane
    jfrm.add(label);

    //make frame visible
    jfrm.setVisible(true);
  }

  public static void main(String args[])
  {
      //creating the frame on event dispatching thread
      //idk multithread programming but here it is
      SwingUtilities.invokeLater(new Runnable(){
        public void run(){
          new swingDemo();
        }
      });
  }

}
