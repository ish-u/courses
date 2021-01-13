class Override extends Base{
	//subclass of Base class
	
	//overriding the sout() function
	void sout(){
		System.out.println("Inside Overriden Function");
	}
	
	//Note that the both the function have the following things as common
	//1. They have the same name
	//2. They have the same type signature (i.e. takes same number of arguments 
	//	 and have same return type)
	//
	//1. and 2. are the necessary condition for function overriding 
	//if not fulfilled the resulting function in the subclass is said to be "overloaded"
	
}