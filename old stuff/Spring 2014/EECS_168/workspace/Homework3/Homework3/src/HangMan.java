
public class HangMan 
{
	private String secret_word;
	private char[] disguised_word;
	private int guessCount;
	private int missesCount;
	private int MAX_MISSES_ALLOWED;
	private char[] missed_Markers;
	int gamesPlayed;
	
	
	public HangMan(String word)
	{
		secret_word=word;
		MAX_MISSES_ALLOWED=7;
		guessCount=0;
		missesCount=0;
		for(int i=0; i<secret_word.length(); i++)
		{
			if(secret_word.charAt(i)==' ')
			{
				disguised_word [i]=' ';
			}
			else
			{
			disguised_word [i]='?';
			}
		}
		for(int i=0; i<MAX_MISSES_ALLOWED; i++)
		{
			missed_Markers[i]='O';
		}
	
		gamesPlayed+=1;
		
	}
	
	public boolean guessCharacter(char c)
	{
		boolean isTrue=false;
		
		for(int i=0; i<secret_word.length(); i++)
		{
			if(c==secret_word.charAt(i))
			{
				isTrue=true;
			}
			
		}
		if(isTrue=false)
		{
		missesCount+=1;
		missed_Markers[missesCount]='X';
		MAX_MISSES_ALLOWED-=1;
		}
		guessCount+=1;
		return(isTrue);
	}
	
	public boolean isGameOver()
	{
		boolean over=true;
		
		for(int i=0; i<secret_word.length();i++)
		{
			if(disguised_word[i]=='?')
			{
				over=false;
			}
		
		}
		if(MAX_MISSES_ALLOWED>0)
		{
			over=false;
		}
		return(over);
	}
	
	public boolean isFound()
	{
		boolean found=true;

		for(int i=0; i<secret_word.length();i++)
		{
			if(disguised_word[i]=='?')
			{
				found=false;
			}
		
		}
		return(found);
	}
	
	public String getDisguisedWord()
	{
		String hidden="";
		for(int i=0;i<secret_word.length(); i++)
		{
			hidden+=disguised_word[i];
		}
		
		return hidden;
	}
	public int getGuessCount()
	{
		int count=guessCount;
		return(count);
		
	}
	
	public int getMissesCount()
	{
		int miss=missesCount;
		return(miss);
		
	}
	
	public String getMissedMarker()
	{
		String missed="";
		for (int i=0; i<secret_word.length(); i++)
		{
			missed+=missed_Markers[i];
		}
		return(missed);
	}
	
	public int getGamesPlayed()
	{
		return(gamesPlayed);
	}

}
