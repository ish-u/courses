import java.io.*;
import java.lang.*;
import java.util.*;

class Distance{
	
	Scanner a = new Scanner(System.in);
	int feet;
	int inch;
	
	//constructor
	Distance(int feet,int inch){
		this.feet = feet;
		this.inch = inch;
		this.feet = this.feet + (this.inch/12);
		this.inch = (this.inch%12);
	}
	
	//input constructor
	Distance(){
		System.out.print("Feet : ");
		this.feet = a.nextInt();
		System.out.print("Inch : ");
		this.inch = a.nextInt();
 		
		feet = feet + (inch/12);
		inch = (inch%12);
	}
	
	//copy constructor
	Distance(Distance a){
		this.feet = a.feet;
		this.inch = a.inch;
	}
	
	//show
	public String toString()
	{
		return this.feet + "\'" + this.inch + "\"" ;
	}
	
	
	
}

class Example_13{
	public static void main(String args[]){
			Distance dist = new Distance();
			System.out.println(dist);
			Distance d1,d2,d3;
			d1 = new Distance(12,48);
			d2 = new Distance(0, 48);
			d3 = d2;
			d3 = new Distance(d1);
			System.out.println(d3);
		
	}
}