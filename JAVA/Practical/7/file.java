import java.io.*;
class file
{
	public static void main(String args[])
	{
		if(args.length != 1)
		{
			System.out.print("Usage - input_file\n");
			System.exit(-1);
		}
		
		String line;
		
		try(FileInputStream fin = new FileInputStream(args[0]);BufferedReader br = new BufferedReader(new InputStreamReader(fin));)
		{
			do
			{
				//reading a line from the file
				line = br.readLine();
				if(line != null)
				{
					//checking if the first two characters are '//' or not
					if(line.charAt(0) == '/' && line.charAt(1) == '/')
					{
						System.out.println(line);
					}
				}
			}
			while(line != null);
		}
		catch(IOException e)
		{
			System.out.print("file can't be opened");
		}
	}
	
}