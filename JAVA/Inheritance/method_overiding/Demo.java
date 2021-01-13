import java.io.*;
class Demo{

	public static void main(String args[]){
		//creating superclass and subclass objects
		Base a  = new Base();
		Override b = new Override();
		
		//creating refrence variable of base class that will be used to access the objects 
		//of respective class it will be pointed at
		
		Base r;
		
		//The following code will call the function respective to the object the refrence is pointing at
		r = a;
		a.sout();
		r = b;
		r.sout();
		
		//sout() here is the overloaded function as it has the same name an type signature
		//but shows different output for objects of differrent classes
			
	}

}