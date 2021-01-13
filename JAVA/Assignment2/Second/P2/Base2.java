package Second.P2;
import Second.P1.Base1;

public class Base2{
    public Base2()
    {
        System.out.println("Package - 2 Base 2");
        Base1 a = new Base1();
        System.out.println(a.publicVariable );
        //Not Accessible
        //System.out.println(a.privateVariable);
        //System.out.println(a.protectedVariable);
    }
    
}
