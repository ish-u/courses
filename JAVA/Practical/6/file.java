import java.io.*;
class file
{
	public static void main(String args[])
	{
		int temp;
		FileInputStream in = null;	//input file
		FileOutputStream out = null;	//output file
		
		if(args.length != 2)
		{
			System.out.print("usage - input_file output_file");
			return;
		}
		
		//copying the file
		try
		{
			//creating file input output objects
			in = new FileInputStream(args[0]);
			out = new FileOutputStream(args[1]);
			
			do
			{
				//reading a single character from the input file and
				//storing it in the variable temp
				temp = in.read();
				if(temp!=-1)
				{
					//writing the obtained character in the output file
					out.write(temp);
				}
			}
			while(temp!=-1);
		}
		catch(IOException e)
		{
			System.out.print("can't open file/s");
		}
		finally
		{
			//closing input file
			try
			{
				if(in!=null)
				{
					in.close();
				}
			}
			catch(IOException e)
			{
				System.out.print("file can't be closed");
			}
			
			//closing output file
			try
			{
				if(out!=null)
				{
					out.close();
				}
			}
			catch(IOException e)
			{
				System.out.print("file can't be closed");
			}
				
		}
	}	
	
}