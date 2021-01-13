class rectangle extends shape{
	
	//constructor
	rectangle(int a, int b)
	{
		super(a,b);
	}
	
	//abstract method redefined for this subclass
	void area(){
		System.out.println("The area of the rectangle is " + dim1*dim2 + " sq.unit");
	}
}