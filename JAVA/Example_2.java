import java.io.*;
class Example_2{
		public static void main(String args[])throws IOException
		{
			int n;
			String s;
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			float t = 0,i;
			System.out.println("Enter the value of n");
			s = br.readLine();
			n = Integer.parseInt(s);
			for(i = 1; i <=n;i++)
			{
				if(i%2==0){
					t -= i;
				}
				else{
					t += i;
				}
				
			}
			System.out.println("The sum of the series that goes 1 - 2 + 3 - 4 + 5 ... " + " whose number of terms are " + n + " is " + t);
			
				
		}
		
}
