import java.io.*;
import java.lang.*;
import java.util.*;
class complex{
	int imaginary;
	int real;
	
	//Constructor default
	complex()
	{
		this.imaginary = 0;
		this.real = 0;
	}
	//Constructor paramerterized
	complex(int imaginary, int real)
	{
		this.imaginary = imaginary;
		this.real = real;
	}
	
	//take input using get function
	void get()
	{
		Scanner a = new Scanner(System.in);
		System.out.print("Enter the real part : ");
		this.real = a.nextInt();
		System.out.print("Enter the imaginary part : ");
		this.imaginary = a.nextInt();
		
	}
	
	//add
	complex add(complex a)
	{
		complex temp = new complex();
		temp.real = this.real + a.real;
		temp.imaginary = this.imaginary + a.imaginary;
		
		return temp;
	}
	
	//multiply
	complex multiply(complex a)
	{
		complex temp = new complex();
		temp.real = (this.real*a.real) - (this.imaginary*a.imaginary);
		temp.imaginary = this.real*a.imaginary + this.imaginary*a.real;
		
		return temp;

		
	}
	
	//show
	public String toString()
	{
		return this.real + " + " + this.imaginary+ "i" ;
	}
}