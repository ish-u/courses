import java.applet.*;
import java.util.*;
import java.awt.event.*;
import java.awt.*;

/*
  <applet code=choiceDemo width=500 height=500></applet>
*/

//this class demonstrate choice control in java awt
//it uses ItemStateChanged() method from the ItemListener interface


public class choiceDemo extends Applet implements ItemListener
{
  //creating a refrence to choice refrence variable
  Choice name;
  Choice age;

   //craeting font object refrence variable
   Font f;

  public void init()
  {
    //creating font object
    f = new Font("SansSerif", Font.PLAIN, 20);
    setFont(f);

    //creating choice object
    name = new Choice();
    age = new Choice();

    //adding options to the choice
    name.add("Ramesh");
    name.add("Suresh");
    name.add("Vrijesh");
    name.add("Rakesh");
    name.add("Sambhu");

    age.add("20");
    age.add("21");
    age.add("22");
    age.add("23");
    age.add("24");
    age.add("25");
    age.add("26");

    //adding objects to the window
    add(name);
    add(age);

    //adding ItemListener
    age.addItemListener(this);
    name.addItemListener(this);

  }

  public void itemStateChanged(ItemEvent i)
  {
    repaint();
  }

  public void paint(Graphics g)
  {
    g.drawString(name.getSelectedItem() + " is " + age.getSelectedItem() + " years old.",30,70);
  }
}
