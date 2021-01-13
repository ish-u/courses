import P1.*; 
import P2.*;
import P3.*;
import java.util.Scanner;

class demo{
	
	public static void main(String args[]){
		//creating a refrence variable of Shape Class from package P1;
		Shape r;
		
		//creating a circle and rectangle object
		rectangle a = new rectangle();
		circle b = new circle();
		
		//asking user whose area they want to find
		boolean flag = true;
		do{
			int choice; //choice variable
			System.out.println();
			System.out.println("Whose area you want to find : ");
			System.out.println("1. Rectangle");
			System.out.println("2. Circle");
			//taking user choice
			Scanner s = new Scanner(System.in);
			choice = s.nextInt();
			//exiting if user don't wanna do anything
			if(choice == 0)
			{
				System.out.println();
				System.out.print("TERMINATING");
				flag = false;
			}
			//using the refrence variable from Superclass Shape to show dynamic method dispatch
			switch(choice)
			{
				case 1:
					r = a;
					r.area();
					break;
				case 2:
					r = b;
					r.area();
					break;
			}
			
			
		}while(flag);
	}
}