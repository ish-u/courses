class stackException extends Exception
{
	//variable for handling underflow or overflow
	private int flag;
	stackException(int flag)
	{
		this.flag = flag;
	}
	
	//overriding the toString() method 
	public String toString()
	{
		if(flag < 0)
		{
			return "Stack Underflow";
		}
		else
		{
			return "Stack Overflow";
		}
	}
	
	
}