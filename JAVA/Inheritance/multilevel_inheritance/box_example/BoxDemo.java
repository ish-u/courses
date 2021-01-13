import java.io.*;
class BoxdDemo{
	
	public static void main(String args[]){
		//creating two boxship objects
		Boxship a = new Boxship(5,10,15,10,250);	//cuboid
		Boxship b = new Boxship(5,20,300);			//cube
		Boxship c = new Boxship(a);					//cloning objec a
		
		//sout volume 
		System.out.println("Volume of Box a - " + a.vol() + " cubic meter");
		System.out.println("Volume of Box b - " + b.vol() + " cubic meter");
		System.out.println("Volume of Box c - " + c.vol() + " cubic meter");	
		System.out.println();
		
		//sout weight
		System.out.println("Weight of Box a - " + a.weight() + " kg");
		System.out.println("Weight of Box b - " + b.weight() + " kg");
		System.out.println("Weight of Box c - " + c.weight() + " kg");
		System.out.println();
		
		//sout shipment
		System.out.println("Shipment Cost of Box a -" + "Rs." + a.shipment());
		System.out.println("Shipment Cost of Box b -" + "Rs." + b.shipment());
		System.out.println("Shipment Cost of Box c -" + "Rs." + c.shipment());
		System.out.println();
		
		
		
		
		
	}
}