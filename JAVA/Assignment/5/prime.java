
class prime{
	
	public static void main(String args[])
	{
		//check whether the user entered a number or not
		if(args.length != 1)
		{
			System.out.println("One Number at a time");
			System.out.print("TERMINATING");
			System.exit(0);
		}
		
		//variable to entered number
		int a = Integer.parseInt(args[0]);
		System.out.println(a);
		
		//check for the number being prime or not
		int flag = 0;
		for(int i = 1; i <= a; i++){
			if(a%i == 0){
				flag++;
			}	
		}
		
		if(flag != 2){
			System.out.print("The Number is not a Prime Number");
		}
		else{
			System.out.print("The Number is a Prime Number");
		}
	}
}