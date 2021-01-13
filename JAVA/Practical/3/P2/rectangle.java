package P2;
import P1.*;
import java.util.Scanner;

public class rectangle extends Shape{
	int length;
	int breadth;
	
	public rectangle(){
		length = 0;
		breadth = 0;
	}
	
	//function to take input and show the area
	public void area(){
		//scanner for taking input
		Scanner s = new Scanner(System.in);
		
		System.out.print("Enter the length : ");
		length = s.nextInt();
		System.out.print("Enter the breadth : ");
		breadth = s.nextInt();
		
		//area of the rectangle
		System.out.println("The area of the rectangle is : " + length*breadth);
		
	}
}