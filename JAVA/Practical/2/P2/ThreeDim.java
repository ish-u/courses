//ThreeDim class belongs to package P2
package P2;

//Importing the TwoDim class from the package P1
import P1.TwoDim;

public class ThreeDim extends TwoDim{
	//private data member z
	private int z;
	
	//default constructor
	public ThreeDim(){
		super();
		z = 0;
	}
	
	//parameterized constructor
	public ThreeDim(int x, int y, int z){
		super(x,y);
		this.z = z;
	}
	
	//overiding the toString() method
	public String toString(){
		return "(" + return_x() + "," + return_y() + "," + this.z + ")";
	}
	
	//method to show dynamic method dispatch
	public void package_name(){
		System.out.println("Package P2");
	}
	
	
}
