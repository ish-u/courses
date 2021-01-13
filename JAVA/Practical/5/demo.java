class demo
{
	public static void main(String args[])
	{
		//creating a stack object
		stack a = new stack(10);
		
		//to show stack overflow
		for(int i = 0; i < 11; i++)
		{
			try
			{
				a.push(i);
			}
			catch(stackException overflow)
			{
				System.out.println(overflow);
				
			}
		}
		
		//to show stack underflow
		for(int i = 0; i < 11; i++)
		{
			try
			{
				System.out.println(a.pop());
			}
			catch(stackException underflow)
			{
				System.out.println(underflow);
			}
		}
	}
}