import java.io.*;
import java.lang.*;
import java.util.*;
class Example_11{
		public static void main(String args[])throws IOException
		{
			complex a = new complex(5,6);
			complex b = new complex(5,6);
			complex c = new complex();
			
			c = a.add(b);
			System.out.println(c);
			System.out.println(a.multiply(b));
			
			a.get();
			b.get();
			
			System.out.println(a.add(b));
			System.out.println(a.multiply(b));
			
		}
		
}