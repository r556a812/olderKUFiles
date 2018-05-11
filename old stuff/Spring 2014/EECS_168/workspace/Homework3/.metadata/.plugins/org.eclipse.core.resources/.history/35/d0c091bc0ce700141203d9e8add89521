import java.util.Scanner;
public class GameDriver 
{
	public static void main(String[] args)
	{
		Scanner kb=new Scanner(System.in);
		String word="big bang";
		HangMan game = new HangMan(word);
		String guess="";
		
		
		System.out.println("Welcome to the Hangman Game!\n----------------------------");
		
		do
		{
		System.out.println("Guess this: " + game.getDisguisedWord());
		System.out.println("Guesses so far: "+game.getGuessCount());
		System.out.println("Misses: "+game.getMissedMarker());
		System.out.println("Enter your guess cahracter: ");
		guess=kb.nextLine();
		if(game.guessCharacter(guess.charAt(0)))
		{
			System.out.println(guess+" is in the secret word!");
			
		}
		else
		{
			System.out.println(guess+" is not in the secret word! Death draws closer.");
		}
		

		
		}while(game.isGameOver()==false);
		
	}
	

}
