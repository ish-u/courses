import java.applet.*;
import java.awt.*;
import java.awt.event.*;


/*
  <applet code=listDemo width=500 height=500></applet>
*/

//listDemo class demonstrate list control of Java AWT
//it uses ActionListener interface actionPerformed() method for event listening
//the source and listener are the objects of same class


public class listDemo extends Applet implements ActionListener
{
  //creating font class refrence variable
  Font f;
  //craeting List class refrence variable
  List l;

  public void init()
  {
    //creating a font object and stting font to SansSerif
    f = new Font("SansSerif", Font.PLAIN, 20);
    setFont(f);

    //creating List object
    l = new List(4,false);

    //adding items to list object l
    l.add("LOL");
    l.add("LMAO");
    l.add("CMAO");
    l.add("SAD");
    l.select(1);

    //adding list to the window
    add(l);

    //adding source to listener
    l.addActionListener(this);

  }

  public void actionPerformed(ActionEvent a)
  {
    repaint();
  }

  public void paint(Graphics g)
  {
    g.drawString("STATUS : " + l.getSelectedItem(), 30, 300);
  }

}
