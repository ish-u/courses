//Complex Class
//1. Add two complex number
//2. Multiply two complex number
//3. print using toString() method

import java.io.*;
import java.lang.*;
import java.util.*; 

class Complex{
	
	//data members
	int real;
	int imaginary;
	
	//default constructor
	Complex(){
		real = imaginary = 0;
	}
	
	//parameterized constructor
	Complex(int real, int imaginary)
	{
		this.real = real;
		this.imaginary = imaginary;
	}
	
	//copy constructor
	Complex(Complex ob)
	{
		real = ob.real;
		imaginary = ob.imaginary;
	}
	
	//function to get user input get()
	void get(){
		
		//Scanner for user input
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the real part : ");
		this.real = s.nextInt();
		System.out.print("Enter the imaginary part : ");
		this.imaginary = s.nextInt();
	}
	
	//add
	//function adds the invoking object and the object passed as parameter and retuns the addition
	//as a temporary object
	Complex add(Complex a){
		
		//temporary object
		Complex temp = new Complex();
		
		temp.real = this.real + a.real;
		temp.imaginary = this.imaginary + a.imaginary;
		
		return temp;
	}
	
	//multiply
	//function adds the invoking object and the object passed as parameter and retuns the addition
	//as a temporary object
	Complex multiply(Complex a){
	
		//temporary object
		Complex temp = new Complex();
		
		temp.real = (this.real*a.real) - (this.imaginary*a.imaginary);
		temp.imaginary = (this.real*a.imaginary) + (this.imaginary*a.real);
		
		return temp;
	}
	
	
	//overriding toString() method to print object of Complex Class
	public String toString(){
		return this.real + " + " + this.imaginary + "i" ; 
	}
	
	
}