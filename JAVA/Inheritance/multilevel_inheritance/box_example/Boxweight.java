class Boxweight extends Box{
	//weight data members (unique member of this subclass whose superclass is Box)
	float w;
	
	//super() is used to call the constructor of superclass of this class
	//defaut constructor
	Boxweight(){
		super();
		w = 0;
	}
	
	//parameterized constructor
	Boxweight(float x, float y , float z, float a){
		super(x,y,z);
		w = z;
	}
	
	//parameterized constructor (cube)
	Boxweight(float p, float a){
		super(p);
		w = a;
	}
	
	//copy constructor
	Boxweight(Boxweight ob){
		super(ob);
		w = ob.w;
	}
	
	//return weight
	float weight(){
		return w;
	}
}