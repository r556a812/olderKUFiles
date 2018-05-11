import java.util.Scanner;

public class MethodPractice 
{
	
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		//Declare Variables
		
		int x=0;
		int y=0;
		int i=0;
		int m;
		String s="";
		int t=0;
		double a=0;
		
		//receive the input for numbers to compare.
		System.out.print("Input two numbers: \n");
		
		//While statement to take in two different numbers.
		while (i<2)
		{
			if(i==0)
			{
			x = input.nextInt();
			}
			if (i==1)
			{
				y = input.nextInt();
			}
			i=i+1;
		}
		
		//call for the use of max.
		m = max(x,y);
		
		System.out.print("The max of " + x + " and " + y + " is: " + m);
		
		System.out.print("\n" + "\n");
		
		//Get the radius for the next question.
		System.out.print("Input a radius: ");
		
		double r=0;
		
		r=input.nextDouble();
		input.nextLine();
		
		//call for the use of sphereArea.
		a=sphereArea(r);
		
		System.out.print("The area of a sphere with this radius is: " + a + "\n");
		
		System.out.print("\n");
		
		//Get the string and the amount of times needed to print it.
		System.out.print("Input a String: \n");
		s=input.nextLine();
		
		
		System.out.print("How many times do you want to print it?: ");
		t=input.nextInt();
		
		
		//Call for the use of printWord.
		printWord(s,t);
		
		
	}
	
		//The setup for max
		public static int max(int a, int b)
		{
			if (a>b)
			{
				return a;
			}
			else
			{
				return b;
			}
		}
		
		//The setup for sphereArea.
		public static double sphereArea(double x)
		{
			double a=0;
			
			if (x>0)
			{
				a = 4*3.14159*x*x;
				return a;
			}
			else
			{
				a=0.0;
				return a;
			}
		}
		
		//The setup for printWord.
		public static void printWord(String word, int times)
		{
			int i=0;
			
			while (i< times)
			{
				System.out.print(word+"\n");
				i=i+1;
			}
		}
}


