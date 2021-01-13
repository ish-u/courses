package P;

//importing package
import P2.*;
import P1.*;

class demo{
	
	public static void main(String args[]){
		
		//making objects of ThreeDim class
		ThreeDim a = new ThreeDim();
		ThreeDim b = new ThreeDim(1,-1,0);
		
		//using the overriding the toString() method 
		System.out.println(a);
		System.out.println(b);
		
		//to show dynamic method dispatch
		TwoDim r; //refrence variable of the super class
		TwoDim x = new TwoDim();
		ThreeDim y = new ThreeDim();
		
		System.out.println("\nTo Show Dynamic Method Dispatch : ");
		x.package_name();
		y.package_name();
		 
	}
	
}