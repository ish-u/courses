	/*
		<applet code=MyApplet width=300 height=400></applet>
		
	*/

import java.awt.*;
import java.applet.*;
class MyApplet extends Applet
{
	public void init(){
		//initialization
		//called only once during the 
		//start of the applet 
	}
	
	public void start(){
		//called each time the focus comes on
		//the applet i.e. applet is opened after
		//being minimized
		//called when the applet is restarted 
	}
	
	public void stop(){
		//called when the focus is not on applet
		//i.e. when the the applet window is minimized
	}
	
	public void paint(){
		//called each time when the output needs to be redrawn on the applet
	}
	
	public void destroy(){
		//called during the termination of the applet
		//i.e. called to release the memory after the applet ends
	}
}