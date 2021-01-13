package P1;

public class TwoDim{
	
	//private data memebers (co-ordinates)
	private int x;
	private int y;
	
	//default constructor
	public TwoDim(){
		x = 0;
		y = 0;
	}
	
	//parameterized constructor
	public TwoDim(int x,int y)
	{
		this.x = x;
		this.y = y;
	}
	
	//overriding the two string method
	public String toString(){
		return "(" + this.x + "," + this.y + ")";
	}
	
	//methods to obtain the private variables
	public int return_x(){
		return x;
	}
	
	public int return_y(){
		return y;
	}
	
	//method to show dynamic method dispatch
	public void package_name(){
		System.out.println("Package P1");
	}
}