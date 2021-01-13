package Second.P1;
//base class
public class Base1{
    public String publicVariable = "public";
    private String privateVariable = "private";
    protected String protectedVariable = "protected";
    public Base1()
    {
        System.out.println("Base1");
        System.out.println(publicVariable);
        System.out.println(privateVariable);
        System.out.println(protectedVariable + "\n");
    }

}

//derived class in the same package
class Derived1 extends Base1{

    Derived1()
    {
        System.out.println("Derived1");
        System.out.println(publicVariable);
        //Not Accessible
        //System.out.println(privateVariable);
        System.out.println(protectedVariable + "\n"); 

    }


} 

//different class in the same package
class anotherClass1{

    anotherClass1()
    {
        System.out.println("anotherClass");
        Base1 a = new Base1();
        System.out.println(a.publicVariable);
        //Not Accessible
        //System.out.println(a.privateVariable);
        System.out.println(a.protectedVariable + "\n");
    }
}


