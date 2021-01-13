import java.io.*;
import java.lang.*;
import java.util.*;
class Example_10{
		public static void main(String args[])throws IOException
		{
			Scanner a = new Scanner(System.in);
			System.out.print("Enter the number : ");
			int num = a.nextInt();
			String sum = "";
			int remainder = 0;
			while(num != 0)
			{
				remainder = num % 2;
				sum += remainder;
				num = num/2;
			}
			
			StringBuilder z = new StringBuilder();
			z.append(sum);
			z = z.reverse();
			System.out.println(z);
			
		}
		
}