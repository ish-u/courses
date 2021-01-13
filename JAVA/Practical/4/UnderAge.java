//Creating a Subclass of the Exception class
class UnderAge extends Exception{

	private int age;	
	UnderAge(int age){
		this.age = age;		
	}
	
	//overriding toString() method to display the desired error
	public String toString(){
		return "The Person is UnderAge : " + age; 
	}
}