class Boxship extends Boxweight{
	//shipment price
	int s;
	
	//super() is used to call the constructor of the superclass of this subclass
	
	//default constructor
	Boxship()
	{
		super();
		s = 0;
	}
	
	//parameterized constructor
	Boxship(float x, float y, float z, float p, int q)
	{
		super(x,y,z,p);
		s = q;
	}
	
	//parameterized constructor (cube)
	Boxship(float a, float b, int c)
	{
		super(a,b);
		s = c;
	}
	
	//copy constructor
	Boxship(Boxship ob)
	{
		super(ob);
		s = ob.s;
		
	}
	
	//return shipment price
	int shipment(){
		return s;
	}
	
	
}