class demo{
	public static void main(String args[])
	{
		//creating objects of class subclass_1 and subclass_2
		subclass_1 a = new subclass_1();
		subclass_2 b = new subclass_2();
		
		//calling the message function for respective objects
		a.message();
		b.message();
	}
}