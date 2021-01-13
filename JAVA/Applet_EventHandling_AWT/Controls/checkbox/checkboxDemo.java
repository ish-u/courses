import java.applet.*;
import java.awt.event.*;
import java.awt.*;
import java.util.*;

/*
  <applet code=checkboxDemo width=500 height=500></applet>
*/

//this program extends Applet class and implements ItemListener interface
//to demonstrate how checkbox works in java awt
//the source and listener are the objects of the same class
//itemStateChanged() method is called in case of an event i.e. cheking or unchecking the checkbox

public class checkboxDemo extends Applet implements ItemListener
{

  String msg = "";  //message to be displayed for the checkboxDemo
  Checkbox A, B, C; //craeting checkbox refrence variables
  CheckboxGroup cbg;  //a group of checkbox
  Font f;
  public void init()
  {
    //setting new Font
    f = new Font("SansSerif", Font.PLAIN, 20);
    setFont(f);

    //creating CheckBoxGroup object
    cbg = new CheckboxGroup();

    //creating checkbox objects
    A = new Checkbox("A",cbg,false);
    B = new Checkbox("B",cbg,false);
    C = new Checkbox("C",cbg,true);

    //adding checkboxes to window using add()
    add(A);
    add(B);
    add(C);

    //adding source to the listener
    A.addItemListener(this);
    B.addItemListener(this);
    C.addItemListener(this);

  }

  public void itemStateChanged(ItemEvent i)
  {
    repaint();
  }

  public void paint(Graphics g)
  {
    g.drawString(A.getLabel() + " : " + A.getState(),10,60);
    g.drawString(B.getLabel() + " : " + A.getState(),10,90);
    g.drawString(C.getLabel() + " : " + C.getState(),10,120);
    g.drawString("Selected : " + cbg.getSelectedCheckbox().getLabel(),10,150);

  }

}
