	/*
		<applet code=music width=400 height=400></applet>
		
	*/

import java.awt.*;
import java.applet.*;

public class music extends Applet{
	
	private AudioClip clip;
	
	public void init()
	{
		clip = getAudioClip(getCodeBase(), "lol.wav");
	}
	public void start()
	{
		clip.loop();
	}
	public void stop()
	{
		clip.stop();
	}
}