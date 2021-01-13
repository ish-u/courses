package P3;
import P1.*;
import java.util.Scanner;

public class circle extends Shape{
	int radius;
	
	public circle(){
		radius = 0;
	}
	
	public void area(){
		//scanner to take input of the radius
		Scanner s = new Scanner(System.in);
		
		System.out.print("Enter the radius of the circle : ");
		radius = s.nextInt();
		System.out.println("The area of the circle is : " + (3.14*radius*radius));
	}
	
}