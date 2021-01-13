class demo{
	public static void main(String args[]){
		
		//Creatiing object of Complex Class
		
		Complex a = new Complex(5,7);
		Complex b = new Complex();
		Complex c = new Complex();
		
		System.out.println("First Complex Number : " + a + "\nEnter the Second Number -> ");
		b.get();
		
		c = a.add(b);
		System.out.println("Addition : " + c);
		System.out.print("Multiplication : " + a.multiply(b));
		
		
	}
}