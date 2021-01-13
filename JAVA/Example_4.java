import java.io.*;
class Example_4{
		public static void main(String args[])throws IOException
		{
			int n;
			String s;
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter the value of n");
			s = br.readLine();
			n = Integer.parseInt(s);
			int fact = 1;
			for(int i = n; i > 0; i--)
			{
				fact *= i;
			}
			System.out.println(fact);
				
		}
		
}
