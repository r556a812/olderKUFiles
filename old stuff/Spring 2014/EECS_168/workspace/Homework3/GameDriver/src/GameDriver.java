import java.util.Scanner;
public class GameDriver 
{
	public static void main(String[] args)
	{
		//Declare variables
		Scanner kb=new Scanner(System.in);
		String word="big bang";
		HangMan game = new HangMan(word);
		String guess="";
		String end="";

		//welcoming the user to the game
		System.out.println("Welcome to the Hangman Game!\n----------------------------");
		//do loop to keep the game running until the user guesses the word or loses.
		
		do
		{
			//If statement to get the next word from the user if they want to play another game. 
			//They have to go through one game before this loop will do anything.
			if(game.getGamesPlayed()>0)
			{
				System.out.println("Input a word: ");
				word=kb.nextLine();
				HangMan newGame = new HangMan(word);

			}
		do
		{
		
		//Print to the user all the information about the current game.
		System.out.println("Guess this: " + game.getDisguisedWord());
		System.out.println("Guesses so far: "+game.getGuessCount());
		System.out.println("Misses: "+game.getMissedMarker());
		//Ask and receive the users guess
		System.out.println("Enter your guess cahracter: ");
		guess=kb.nextLine();
		guess=guess.toLowerCase();
		
		//If statement to know what to display to the user whether or not they guessed right or wrong.
		if(game.guessCharacter(guess.charAt(0)))
		{
			System.out.println(guess+" is in the secret word!");
			
		}
		else
		{
			System.out.println(guess+" is not in the secret word! Death draws closer.");
		}
		

		//Loop ending condition.  If they lose or guess the word it will stop the game.
		}while(game.isGameOver()==false);
		System.out.println("Game Over! \nDo you want to play again? (yes/no) ");
		end=kb.nextLine();
		end=end.toLowerCase();

		
		}while(end=="yes");
	}
	
	
	

}