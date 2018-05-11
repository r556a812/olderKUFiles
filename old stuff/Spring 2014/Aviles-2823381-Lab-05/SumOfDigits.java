import java.util.Scanner;

public class SumOfDigits 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		//Declare variables.
		int i=0;
		int a=0;
		int u=1;
		
		//Do loop to keep it going until the user is done using it.
		do
		{
		System.out.print("Please enter a No: \n"); //Get the user number input.
		i = input.nextInt();
		
		a = addDigits(i); //Call for addDigits to add all the numbers up.
		
		System.out.print("The sum of the digits is: " + a + "\n");  
		
		System.out.print("\nWant to try again?(y=1/n=0) : \n");  //Ask the user if they want to keep doing it.
		u=input.nextInt();
		System.out.print("\n");
		}while(u!=0); //Ending condition; will end only if the user gives a 0 input.
		
		System.out.print("\nThank you!");
		
		
	}
	
	//The setup for addDigits to add up a given number from the user.
	public static int addDigits( int x)
	{
		int s=0;
		while (x>0)
		{
			s=s+(x%10);
			x=x/10;
		}
		return s;
	}
}
