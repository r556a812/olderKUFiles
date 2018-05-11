import java.lang.Math;
import java.util.Scanner;
public class Hypotenuse 
{
	public static void main(String[] args)
	{
		//Create a scanner object.
		Scanner input = new Scanner(System.in);
		
	//Declare the variable and constants.
	double answer;
	double a;
	double b;
	
	System.out.println("Will use the formula a^2 + b^2 = c^2 to solve for the hypotenuse of a triangle.");
	System.out.println("Input a value for a:");
	
	//Read the input from the keyboard.
	a = input.nextDouble();
	
	System.out.println("Input a value for b:");
	
	//Read the input from the keyboard.
	b = input.nextDouble();
	
	//Calculate the answer.
	answer = Math.sqrt((a*a)+(b*b));
	
	System.out.println("The hypotenuse is : " + answer);
	}
	
	
	
	
	

}
