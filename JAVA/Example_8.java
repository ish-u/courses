import java.io.*;
import java.util.Scanner;
class Example_8{
		public static void main(String args[])throws IOException
		{
			Scanner a = new Scanner(System.in);
			int array_size = a.nextInt();
			int array[];
			array = new int[array_size];
			for(int i = 0; i < array_size; i++)
			{
				System.out.print("Enter the " + (i+1) + "th element of array");
				array[i] = a.nextInt();
			}
			for(int j = 0; j < array_size; j++)
			{
				System.out.println(array[j]);
			}
			
		}
		
}