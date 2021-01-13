class Test{
    
    //constructor
    Test()
    {
        System.out.print("Default Constructor\n");
    }

    //parameterized constructor
    Test(String a)
    {
        System.out.println("Parameterized COntsructor \n" + "Hello " + a);
    }

    //method overloading with different number of parameter
    void function(int a)
    {
        System.out.println("form - function(int a)");
        System.out.println("a : " + a+ "\n");
    }

    void function(int a, int b)
    {
        System.out.println("form - function(int a,int b)");
        System.out.println("a : " + a);
        System.out.println("b : " + b+ "\n");
        
    }

    //method overloading with different type of parameter
    void function(char a)
    {
        System.out.println("form - function(char a)");
        System.out.println("a : " + a+ "\n"); 
    }

    void function(double a, double b)
    {
        System.out.println("form - function(double a, double b");
        System.out.println("a : " + a);
        System.out.println("b : " + b + "\n");


    }

    //method overloading with different sequence of parameter
    void function(float a, int b)
    {
        System.out.println("form - function(float a, int b");
        System.out.println("a : " + a);
        System.out.println("b : " + b+ "\n");
    }

    void function(int a, float b)
    {
        System.out.println("form - function(int a, float b");
        System.out.println("a : " + a);
        System.out.println("b : " + b+ "\n");
    }

    //main() function
    public static void main(String args[])
    {
        //creating two objects -
        //one using default constructor and 
        //the other using parameterized constructor
        Test a = new Test();
        Test b = new Test("Anmol");
        System.out.print("\n");
        //calling function 
        a.function(10);
        a.function('y');
        a.function(10,20);
        a.function(28000000000000d, 2100000000000d);
        b.function(3.145, 77);
        b.function(77, 3.145);

    }

}
