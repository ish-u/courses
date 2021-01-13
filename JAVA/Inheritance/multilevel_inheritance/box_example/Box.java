class Box{
	
	//length breadth height of the box
	float l;
	float b;
	float h;
	
	//default constructor
	Box(){
		l = 0;
		b = 0; 
		h = 0;
	}
	
	//parameterized constructor
	Box(float x, float y, float z){
		l = x; b = y; h = z;
	}
	
	//parameterized constructor (cube)
	Box(float p)
	{
		l = b = h = p;
	}
	
	//copy constructor
	Box(Box ob){
		l = ob.l;
		b = ob.b;
		h = ob.h;
	}
	//volume method
	float vol(){
		return l*b*h;
	}
	
}