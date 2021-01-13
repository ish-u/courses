import java.io.*;
class Example_6{
		public static void main(String args[])throws IOException
		{
			int sum = 0,num;
			for(int i = 0; i < args.length;i++)
			{
				num = Integer.parseInt(args[i]);
				sum += num;
			}
			System.out.println("The sum of the number entered as Command Line arguments " + sum);
				
		}
		
}
