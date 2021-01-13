import java.io.*;
class Example_3{
		public static void main(String args[])throws IOException
		{
			int n;
			int sum = 0;
			String s;
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter the value of n");
			s = br.readLine();
			n = Integer.parseInt(s);
			int rem;
			while(n !=0)
			{
				rem = n%10;
				sum = (sum*10) + rem;
				n = n/10;
			}
			System.out.println(sum);
			
				
		}
		
}
