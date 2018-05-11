import java.util.Scanner;

public class WordGuessingGame 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		//Declare variable
		String w;
		//greet the user
		System.out.print("Welcome to the word guessing game.");
		//Ask the user for their input.
		System.out.print("\nGuess a word: ");
		
		
		//Create the do-while-loop.
		do
		{
			//Receive the input. Inside the do-loop to ask again until they guess correctly.
			w = input.nextLine(); 
			//If statement for the wrong guess.
			if (!(w.equals("valentine")))
			{
				System.out.print("Incorrect. Guess again: ");//Display to the user they guessed wrong.
			}
		}while (!(w.equals("valentine"))); //While statement to keep the loop going until they guess right.
		
		System.out.println("You win!"); //Display to the user when they guess correctly.
		
	}

}
