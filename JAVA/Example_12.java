import java.io.*;
import java.lang.*;
import java.util.*;

class funcOverloading
{
	void one(byte a, byte b){
		System.out.println("Byte Byte");
		
	}
	void one(int a, int b){
		System.out.println("int int");
		
	}
	void one(char a, char b){
		System.out.print("char char");
	}
	void one(short a, short b)
	{
		System.out.println("short short");
	}
	void one(long a, long b)
	{
		System.out.println("long long");
	}
	void one(float a, float b){
		System.out.println("float float");
	}
	void one(double a,double b)
	{
		System.out.println("double double");
	}
	
	
}

class Example_12{
	public static void main(String args[])throws IOException
	{
		byte b = 20;
		int i = 256000;
		short s = 1280;
		char c = 'a';
		float f = 1280.002f;
		double d = 22E14d;
		long l = 125235646546431L;
		funcOverloading a = new funcOverloading();
		
		//byte -> short -> int -> long
		a.one(b, i);
		a.one(s, i);
		a.one(i,l);
		a.one(b,l);
		a.one(s,l);
		
		//float -> double
		a.one(f,d);
		a.one(d,f);
		
		//char -> int
		a.one(c,i);
		a.one(i,c);
		
	}
}