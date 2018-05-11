
public class HangMan 
{
	//Declare variables
	private String secret_word;
	private char[] disguised_word;
	private int guessCount;
	private int missesCount;
	private int MAX_MISSES_ALLOWED;
	private char[] missed_Markers;
	int gamesPlayed;
	
	//Constructor to set all the values to a standard amount
	public HangMan(String word)
	{
		
		secret_word=word.toLowerCase();
		MAX_MISSES_ALLOWED=7;
		guessCount=0;
		missesCount=0;
		//For loop to input the right amount of ? in for the disguised word.
		for(int i=0; i<secret_word.length(); i++)
		{
			if(secret_word.charAt(i)==' ')
			{
				disguised_word [i]=' ';
			}
			else
			{
			disguised_word [i] = '?';
			}
		}
		
		//For loop to put the right of miss markers in the variable missed_Markers.
		for(int i=0; i<MAX_MISSES_ALLOWED; i++)
		{
			missed_Markers[i]='O';
		}
	
		gamesPlayed+=1;
		
	}
	//Method to tell if the guessed letter is in the word
	public boolean guessCharacter(char c)
	{
		boolean isTrue=false;
		//For loop to see if the guessed letter is in the secret word.
		for(int i=0; i<secret_word.length(); i++)
		{
			if(c==secret_word.charAt(i))
			{
				isTrue=true;
				disguised_word[i]=c;
			}
			
		}
		//Updating the information if the user guesses wrong.
		if(isTrue=false)
		{
		missesCount+=1;
		missed_Markers[missesCount]='X';
		MAX_MISSES_ALLOWED-=1;
		}
		//Adding to the guess count everytime the user guesses.
		guessCount+=1;
		return(isTrue);
	}
	//method to know if the game is over either by guessing the word or missing too many times
	public boolean isGameOver()
	{
		boolean over=true;
		//For loop to see if the user has guessed the entire word.
		for(int i=0; i<secret_word.length();i++)
		{
			if(disguised_word[i]=='?')
			{
				over=false;
			}
		
		}
		//If statement for if the user guesses wrong too many times.
		if(MAX_MISSES_ALLOWED>0)
		{
			over=false;
		}
		return(over);
	}
	//method to know if the user has guessed all the right letters.
	public boolean isFound()
	{
		boolean found=true;
		//for loop to see if there are any ? left
		for(int i=0; i<secret_word.length();i++)
		{
			if(disguised_word[i]=='?')
			{
				found=false;
			}
		
		}
		return(found);
	}
	//method to return the disguised word to the game driver
	public String getDisguisedWord()
	{
		String hidden="";
		//for loop to put the disguised word into a variable that can be returned
		for(int i=0;i<secret_word.length(); i++)
		{
			hidden+=disguised_word[i];
		}
		
		return hidden;
	}
	//method to return the guess count to the game driver.
	public int getGuessCount()
	{
		int count=guessCount;
		return(count);
		
	}
	//method to return the missed count to the game driver.
	public int getMissesCount()
	{
		int miss=missesCount;
		return(miss);
		
	}
	//method to return the missed markers to the game driver.
	public String getMissedMarker()
	{
		String missed="";
		for (int i=0; i<secret_word.length(); i++)
		{
			missed+=missed_Markers[i];
		}
		return(missed);
	}
	//method to show the amount of games played to the game driver.
	public int getGamesPlayed()
	{
		return(gamesPlayed);
	}

}
