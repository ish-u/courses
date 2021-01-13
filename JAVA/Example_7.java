import java.io.*;
import java.util.Scanner;
class Example_7{
		public static void main(String args[])throws IOException
		{
			Scanner a = new Scanner(System.in);
			int n = a.nextInt();
			int fact = 1;
			for(int i = n; i > 0; i--)
			{
				fact *= i;
			}
			System.out.println("Factorial " + fact);
				
		}
		
}
