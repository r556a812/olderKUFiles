import java.util.Scanner;
public class Multiples 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		int multiples;
		int amount;
		
		System.out.println("What number do you wish to see multiples of?");
		
		multiples = input.nextInt();
		
		System.out.println("How many multiples?");
		
		amount = input.nextInt();
		
		
		System.out.println("Here are the first " + amount + " multiples of " + multiples);
		
		for (int i=multiples; i<=(multiples*amount); i=i+multiples)
		{System.out.println(i);
		}
		
		if (amount <= 0)
		{System.out.println(" Error: The amount of multiples to display must be greater than 0");
		}
	}

}

