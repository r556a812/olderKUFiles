import java.util.Scanner;

public class Pyramid 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		//Declare variable
		int n = 0;
		//Display to the user the question.
		System.out.print("Enter the number of asterisks for the base of the triangle: ");
		//Receive the user inputed number.
		n = input.nextInt();
		//Create the for-loop for the number of rows.
		for (int outside = 1; outside < n+1; outside++ )
		{
			//For-loop for the number of astericks in the rows.
			for ( int inside = 0; inside < outside; inside++)
			{
				System.out.print("*"); //print the astericks on the screen.
			}
			System.out.print("\n"); //to create a new line after each row.
		}
	}

}
