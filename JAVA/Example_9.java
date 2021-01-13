import java.io.*;
import java.util.Scanner;
class Example_9{
		public static void main(String args[])throws IOException
		{
			Scanner a = new Scanner(System.in);
			int matrix_1[][];
			int matrix_2[][];
			int row_1,col_1;
			int row_2,col_2;			
			
			//definig matrix 1
			System.out.println("Enter the Dimension of Matrix 1");
			System.out.print("Row : ");
			row_1 = a.nextInt();
			System.out.print("Col : ");
			col_1 = a.nextInt();
			matrix_1 = new int[row_1][col_1];
			System.out.println("");
			
			//definig matrix 2			
			System.out.println("Enter the Dimension of Matrix 2");
			System.out.print("Row : ");
			row_2 = a.nextInt();
			System.out.print("Col : ");
			col_2 = a.nextInt();	
			matrix_2 = new int[row_2][col_2];
			
			//taking input
			System.out.println("");	
			System.out.println("");
			System.out.println("Matrix-1");
			for(int i = 0; i < row_1; ++i)
			{
				for(int j = 0; j < col_1; ++j)
				{
					System.out.print("Enter the " + i + "" + j + "-element of matrix : ");
					matrix_1[i][j] = a.nextInt();
				}
			}
			
			System.out.println("");
			System.out.println("Matrix-2");
			for(int i = 0; i < row_2; ++i)
			{
				for(int j = 0; j < col_2; ++j)
				{
					System.out.print("Enter the " + i + "" + j + "-element of matrix : ");
					matrix_2[i][j] = a.nextInt();
				}
				
			}
			
			//addition
			System.out.println("");
			if((row_1 == row_2) && (col_1 == col_2))
			{
				int matrix[][];
				matrix = new int[row_1][col_1];
				for(int i = 0; i < row_1; ++i)
				{
					for(int j = 0; j < col_1; ++j)
					{
						matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
					}
				}
				System.out.println("Addition : ");
				for(int i = 0; i < row_1; ++i)
				{	
					for(int j = 0; j < col_1; ++j)
					{
						System.out.print("\t" + matrix[i][j]);
					}
					System.out.println("");
				}	
			}
			else
			{
				System.out.println("Can\'t Add");
			}
			
			//subtraction
			if((row_1 == row_2) && (col_1 == col_2))
			{
				int matrix[][];
				matrix = new int[row_1][col_1];
				for(int i = 0; i < row_1; ++i)
				{
					for(int j = 0; j < col_1; ++j)
					{
						matrix[i][j] = matrix_1[i][j] - matrix_2[i][j];
					}
				}
				System.out.println("Subtraction : ");
				for(int i = 0; i < row_1; ++i)
				{	
					for(int j = 0; j < col_1; ++j)
					{
						System.out.print("\t" + matrix[i][j]);
					}
					System.out.println("");
				}	
			}
			else
			{
				System.out.println("Can\'t Subtract");
			}
			
			//multiplication
			if((col_1 == row_2))
			{
				int matrix[][];
				matrix = new int[row_1][col_2];
				for(int i = 0; i < row_1; ++i)
				{
					for(int j = 0; j < col_2; ++j)
					{
						for(int k = 0; k < col_1; ++k)
						{
							matrix[i][j] += matrix_1[i][k]*matrix_2[k][j];
						}
					}
				}
				System.out.println("Multiplication : ");
				for(int i = 0; i < row_1; ++i)
				{	
					for(int j = 0; j < col_2; ++j)
					{
						System.out.print("\t" + matrix[i][j]);
					}
					System.out.println("");
				}	
			}
			else
			{
				System.out.println("Can\'t Multiply");
			}
			
			//transpose
			System.out.println("");
			System.out.println("Matrix-1");
			for(int i = 0; i < row_1; ++i)
			{	
				for(int j = 0; j < col_1; ++j)
				{
					System.out.print("\t" + matrix_1[j][i]);
				}
				System.out.println("");
			}
			
			System.out.println("");
			System.out.println("Matrix-2");
			for(int i = 0; i < row_2; ++i)
			{	
				for(int j = 0; j < col_2; ++j)
				{
					System.out.print("\t" + matrix_2[j][i]);
				}
				System.out.println("");
			}
			
			
			
			
		}
		
}