import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class letterCounter 
{
	public static void main(String[] args)
	{
		//Declare variables
		Scanner kb = new Scanner(System.in);
		String file=null;
		String outFile=null;
		FileWriter fWriter=null;
		BufferedWriter bWriter=null;
		FileReader fReader = null;
		BufferedReader bReader = null;
		
		//Do loop to make sure the user gives a valid file name
		do
		{
			//try-catch to get a file name and what to do if it isnt valid.
			try
			{
				//Receive the file name and store it in variable file.
			System.out.print("Input a file name: ");
			file=kb.nextLine();
			//Create the file reader and buffer reader with the stored file given.
			fReader = new FileReader(file);
			bReader = new BufferedReader(fReader);
			}
			catch (Exception e)
			{
				System.out.println("Invalid filename given. Input another.");
				file=null;
			}
		} while (file==null); //keeps the loop going until the user gives a valid file name, which changes from null to the file name.
		
		
		//do loop to receive a correct name for an outfile.
		do
		{
			
		
		try
		{
			//Receive the outfile name from user
		System.out.print("\nInput an out file name:");
		outFile=kb.nextLine();
		//Create the file and buffered writer to transfer the information.
		fWriter = new FileWriter(outFile);
		bWriter = new BufferedWriter(fWriter);
		}
		catch (Exception e)
		{
			System.out.println("Invalid filename given. Input another.");
			outFile=null;
		}
		
		}while (outFile==null); //keeps the loop going until a correct out file name is given.
		
		System.out.println("\nReading from " + file + "\n"); 
		
		//Created an array to keep count of how many of each letter is used.
		int [] letterArray = new int[52];
		//For loop to set the initial values to 0 in the array.
		for (int i =0; i<52; i++)
		{
			letterArray[i]=0;
		}
		
		//Try-catch to transfer the data to the outfile, read and print to the user what is in the file, and store the calculations of how many of each letter are in the file.
		try
		{
		String line; // string to store each line of the file in.
		line = bReader.readLine();
		
		while (line!=null)//While loop that goes until the file is null.
		{
			//For loop to go through each char in the line of the file.
			for (int r=0; r<line.length(); r++)
			{
				//If statement to store the capital letters in a corresponding array number (0-25 = A-Z)
				if ((int)line.charAt(r)>=65 && (int)line.charAt(r)<=90)
				{
					
					letterArray[(int)line.charAt(r)-65]+=1;
				}
				//Is statement to store the lowercase letters in a corresponding array number (26-52 = a-z)
				if ((int)line.charAt(r)>=97 && (int)line.charAt(r)<=122)
				{
					letterArray[(int)line.charAt(r)-71]+=1;
				}
			}
			bWriter.write(line); //Write each line into the output file.
			System.out.println(line);//Print to the user each line in the file.
			line = bReader.readLine();//Read off the next line in the file.
		}
		
		bReader.close();
		bWriter.close();
		}
		catch (Exception e)
		{
			System.out.println(e.getMessage());
		}
		
	System.out.println("Results are stored in " + outFile);
	
		//For loop to display the capital letters and their corresponding amount of times they appeared in the file.
		for (char ch='A'; ch<='Z'; ch++)
		{
			int arrayNumber = (int)ch;
			System.out.println(ch + "="+letterArray[arrayNumber-65]);
		
		}
		//For loop to display the lowercase letters and their corresponding amount of times they appeared in the file.
		for (char ch='a'; ch<='z'; ch++)
		{
			int arrayNumber = (int)ch;
			System.out.println(ch + "="+letterArray[arrayNumber-71]);
		
		}
		
		
		
		
		
	}

}
