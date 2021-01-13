import java.io.*;
class Example_5{
		public static void main(String args[])throws IOException
		{
			int n;
			String s;
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter the value of n");
			s = br.readLine();
			n = Integer.parseInt(s);
			int a = 0;
			for(int i = 1; i <= n;i++)
			{
				if(n%i == 0)
				{
					a++;
				}
			}
			
			if(a == 2)
			{
				System.out.println("The number is Prime ");
			}
			else
			{
				System.out.println("The Number is not prime");
			}
				
		}
		
}
