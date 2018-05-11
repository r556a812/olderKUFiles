import java.util.Scanner;

public class SummationOfFives
{

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		// Declare variables
		int number;
		int sum=0;
		int mult5;
		
		//Display what you want to ask the user.
		System.out.print("Please input a positive integer as the end value: ");
		
		//Get the user input.
		number = input.nextInt();
		
		//Convert the input to a for sure multiple of 5.
		mult5 = number/5;
		mult5 = mult5*5;
		
		//Create the while loop to add the multiples of 5.
		while (mult5>0)
		{
			sum = sum+mult5;
			
			mult5 = mult5-5;
		}
		
		//Print out the sum for the user.
		System.out.print(sum);
		
		
	}
		
	}
	