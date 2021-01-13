import java.io.*;
class Example{
		public static void main(String args[])throws IOException
		{
			int n;
			String s;
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			float t = 0,i;
			System.out.println("Enter the value of n");
			s = br.readLine();
			n = Integer.parseInt(s);
			for(i = 1;i<=n;i++)
			{
				t +=1/i;
			}
			System.out.println("Total :"+t);
			}
		
}
