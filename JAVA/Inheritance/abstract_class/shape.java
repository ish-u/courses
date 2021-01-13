abstract class shape{
	//this is an abstract class for a two dimensional figure;
	int dim1;
	int dim2;
	
	shape(int a, int b)
	{
		dim1 = a;
		dim2 = b;
	}
	
	//abstract method (needs to be redefined during inheritance)
	abstract void area();
}