import java.util.Scanner;
public class array 
{
	public static void main(String[] args)
	{
		//Declare variables
		Scanner kb = new Scanner (System.in);
		int size = 0;
		int num [] = null;
		
		//Do statement to make sure the user inputs a number greater than 1 for the array size
		do
		{
		System.out.print( "Input an array size: ");
		size = kb.nextInt();
		}while (size<=0);
		
		//Assign the size of the array
		num = new int [size];
		
		System.out.println("Now please enter " + size + " numbers");
		
		//For loop to get the arary values from the user
		for (int i=0; i<size; i++)
		{
			System.out.print("Input a number into your array: ");
			num [i]=kb.nextInt();
		}
		
		//For loop to display the numbers the user gave
		System.out.println("Here are all the numbers in your array:" );
		for (int i=0; i<size; i++)
		{
			System.out.println(num [i]);
		}
		
		//For loop to add the number given from the user
		int sum=0;
		for (int i=0; i<size; i++)
		{
			sum=sum+num[i];
			
		}
		
		System.out.println("The sum of all the values is: " + sum);
		
		//Print out the average of the numbers. No loop needed since its simple division
		//of two variables that have already been calculated (Sum and Size).
		System.out.println("The average of all the values is: " + (sum/size));
		
		//For loop to find the biggest number given from the user
		int max=0;
		for (int i=0; i<size; i++)
		{
			if (max<num[i])
			{
				max=num[i];
			}
			
		}
		
		System.out.println("The largest value is: " + max);
		
		//For loop to find the smallest number the user gave
		int min=sum;
		for (int i=0; i<size; i++)
		{
			if (min>num[i])
			{
				min=num[i];
			}
			
		}
		
		System.out.println("The smallest value is: " + min);
		
		
		

	}
	

}
