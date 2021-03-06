import java.util.Scanner;
public class lab07 
{
	public static void main(String [] args)
	{
		//Declare variables for the array
		Scanner kb = new Scanner(System.in);
		int size = 0;
		double [] array = null;
		
		//Do statement to make sure the user inputs a number greater than 1 for the array size
		do
		{
			System.out.print( "Input an array size: ");
			size = kb.nextInt();
		}while (size<=0);
		
		System.out.print("\n");
		
		//Assign the size of the array
		array = new double [size];
				
		System.out.println("Now please enter " + size + " numbers");
				
		//For loop to get the array values from the user
		for (int i=0; i<size; i++)
		{
			System.out.print("Input a number into your array: ");
			array [i]=kb.nextDouble();
		}
		//Call method to print the numbers in the array.
		printArray(array);
		
		System.out.print("\n\n");
		//declare variable for the new size
		int newSize = 0;
		//Do statement to make sure the new array size is bigger than the old one
		do
		{
			System.out.print( "Input a new size: ");
			newSize = kb.nextInt();
		}while (newSize<size+1);
		
		//Declare the new array and getting the old values put into the new array with the call method
		double [] newArray= arrayResize(array, newSize);
		//Let the user know how many new numbers to add.
		System.out.print("You need to add " + (newSize-size) + " values\n");
		//For statement to get the new values to put into the array
		for (int i=size; i<newSize; i++)
		{
			System.out.print("Input a number to add to your array: ");
			newArray[i]=kb.nextDouble();
		}
		//Call method to print the values in the new array
		printArray(newArray);
		
		System.out.print("\n\n");
		//declare the variable to get the value to count
		double value=0;
		//Ask and store the value they want
		System.out.print("Enter a value to count: ");
		value = kb.nextDouble();
		//Declare new variable amount that gets its value from the method call count
		int amount = count(newArray, value);
		//If statement to print one way if the amount is 1 or not a 1.
		if (amount!=1)
		{
		System.out.println(value + " occurs " + amount + " times in the array.");
		}
		else
		{
			System.out.println(value + " occurs " + amount + " time in the array.");

		}
		//Declare varaiable to store my max and min from the method calls
		double large = max(newArray);
		double small = min(newArray);
		//Print the max and min values to the user
		System.out.println("Min value in the array: " + small);
		System.out.println("Max value in the array: " + large);
		
	}
				
		
	//Method to print the array given to the method
	public static void printArray(double [] arr)
	{
		//For loop to display the numbers the user gave
				System.out.print("Here are all the numbers in your array:\n[" );
				for (int i=0; i<arr.length; i++)
				{
					if (i<arr.length-1)
					{
					System.out.print(arr[i] + ", ");
					}
					else
					{
						System.out.print(arr[i]);
					}
				}
				System.out.print("]");
				
	}
	
	
	//Method to resize the array and keep the old values
	public static double[] arrayResize(double[] oldArray, int newSize)
	{
		//Declare new variable to store the old values into
		double [] newArray= new double [newSize];
		//For loop to transfer old values into the new array
		for (int i=0; i<oldArray.length; i++)
		{
			newArray[i]=oldArray[i];
			
		}
		//For loop to make the remaining values a 0.
		for (int i=oldArray.length; i<newArray.length; i++)
		{
			newArray[i]=0;
		}
		
		return (newArray);
		
	}
	
	//Method to count the value the user asked about.
	public static int count(double [] arr, double value)
	{
		int amount = 0;
		//For statement to go through each value in the array and check if it matches the value looking for.
		for (int i=0; i<arr.length; i++)
		{
			//If statement to count the amount of times the value appears.
			if (arr[i] == value)
			{
				amount = amount +1;
			}
		}
		
		return (amount);
	}
	
	//Method to find the max value
	public static double max(double[] arr)
	{
		//declare variable to store the max in
		double max=arr[0];
		//for loop to go through each value in the array
		for (int i=0; i<arr.length; i++)
		{
			//if statement to find the largest value
			if (arr[i]>max)
			{
				max=arr[i];
			}
		}
		return(max);
	}
	
	//Method to find the min value
	public static double min(double[] arr)
	{
		//declare variable to store the min in
		double min=arr[0];
		//for statement to go through each value in the array
		for (int i=0; i<arr.length; i++)
		{
			//if statement to find the smallest value
			if (arr[i]<min)
			{
				min=arr[i];
			}
		}
		return(min);
		
	}
	
}
	


