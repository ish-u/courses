class exceptionDemo{
	
	//the test method throws an object Of class UnderAge 
	static void test(int age) throws UnderAge
	{
		if(age < 18){
			//throwing an object of class UnderAge
			throw new UnderAge(age);
		}
		else{
			System.out.println("NOT UNDER AGE");
		}
	}
	
	//main method
	public static void main(String args[])
	{
		//using try catch on the function test() defined in exceptionDemo class
		//---------------------------------
		try
		{
			test(7);			
		}
		catch(UnderAge age)
		{
			System.out.println(age);
		}
		//---------------------------------
		
		//---------------------------------
		try
		{
			test(18);			
		}
		catch(UnderAge age)
		{
			System.out.println(age);
		}
		//---------------------------------
		
		//--------------------------------
		try
		{
			test(20);			
		}
		catch(UnderAge age)
		{
			System.out.println(age);
		}
		//---------------------------------
		
		//--------------------------------
		try
		{
			test(37);			
		}
		catch(UnderAge age)
		{
			System.out.println(age);
		}
		//---------------------------------
	}
}