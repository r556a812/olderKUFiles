import java.util.Scanner;

public class SquareMatrix 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		//Declare variables.
		int size;
		int multiple=0;
		int adder=0;
		
		//Ask for the size of the matrix desired.
		System.out.print("Enter the Size of the Square Matrix: \n");
		size = input.nextInt();
		
		System.out.print("Square Matrix: \n");
		
		//Nested for loops to give the square matrix.
		for (int o=1; o<=size; o=o+1)
		{
			for (int i=1; i<=size; i=i+1)
			{
				System.out.print(i+multiple + " ");
			}
			System.out.print("\n");
			multiple=size+multiple;
		}
		
		System.out.print("Transpose: \n");
		
		//Nested for loops to give the transpose matrix.
		for (int oo=1; oo<=size; oo=oo+1)
		{
			adder=size;
			System.out.print(oo + " ");
			
			for (int ii=1; ii<size; ii=ii+1)
			{
			System.out.print(oo+adder + " ");
			adder=adder+size;
			}
			System.out.print("\n");
		
		}
	}

}
