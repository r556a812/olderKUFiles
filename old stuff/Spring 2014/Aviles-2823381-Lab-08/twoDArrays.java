import java.util.Scanner;
public class twoDArrays 
{
	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);
		int column=0;
		int row=0;
		int [][] array=null;
		
		System.out.print("How many rows?: ");
		row=kb.nextInt();
		System.out.print("How many columns?: ");
		column=kb.nextInt();
		
		array=new int [row][column];
		
		for (int i=0; i<row; i++)
		{
			for (int j=0;j<column;j++)
			{
				System.out.print("Enter a value for position ("+i+","+j+"): ");
				array[i][j]=kb.nextInt();
			}
			
		}
		
		print2DArray(array);
		
		for (int i=0; i<row; i++)
		{
			int sum=arraySum(array[i]);
			double avg=arrayAvg(array[i]);
			System.out.println("row "+i+" sum= "+sum+", avg = "+avg);
		}
		
		int max=arrayMax2D(array);
		System.out.println("The largest value in the array is = "+max);
		
		int sum2D=arraySum2D(array);
		System.out.println("The sum for the entire array is = "+sum2D);
		
		double avg2D=arrayAvg2D(array);
		System.out.println("The average of the entire array is = "+avg2D);
		
		
		
	}
	
	public static void print2DArray(int [][] array)
	{
		
		System.out.println("Here is your array");
		for (int i=0; i<array.length; i++)
		{
			for (int j=0;j<array[i].length;j++)
			{
				if(j<array[i].length-1)
				{
					System.out.print(array[i][j]+", ");
				}
				else
				{
					System.out.print(array[i][j]);
				}
			}
			System.out.print("\n");
		}
	}
	
	
	public static int arraySum(int [] array)
	{
		int sum=0;
		for (int i=0;i<array.length;i++)
		{
			sum=sum+array[i];
		}
		return (sum);
		
		
	}
	
	public static double arrayAvg(int [] array)
	{
		double sum=0;
		double avg=0;
		
		for (int i=0;i<array.length;i++)
		{
			sum=sum+array[i];
		}
		avg=sum/array.length;
		
		return(avg);
		
	}
	
	public static int arraySum2D(int [][] array)
	{
		int sum=0;
		
		for (int i=0; i<array.length; i++)
		{
			for (int j=0;j<array[i].length;j++)
			{
			sum=sum+array[i][j];	
			}
			
		}
		return(sum);
		
	}
	
	public static double arrayAvg2D(int [][] array)
	{
		double sum=0;
		double amount=0;
		
		for (int i=0; i<array.length; i++)
		{
			for (int j=0;j<array[i].length;j++)
			{
			sum=sum+array[i][j];	
			amount=amount+1;
			}
			
		}
		
		double avg=sum/amount;
		return(avg);
		
	}
	
	public static int arrayMax2D(int [][] array)
	{
		int max=array[0][0];
		
		for (int i=0; i<array.length; i++)
		{
			for (int j=0;j<array[i].length;j++)
			{
			if (array[i][j]>max)
			{
				max=array[i][j];
			}
			}
			
		}
		return(max);
		
	}
	
	

}
