import java.util.Scanner;
public class KUStudentTest 
{
	public static void main(String[] args)
	{
		//Declare variables.
		Scanner kb=new Scanner(System.in);
		String name="";
		String ku="";
		String fname="";
		String lname="";
		String kuid="";
		String dpt="";
		int n=0;
		int k=0;
		
		//Ask the user for the first and last name, in that order.
		System.out.println("Please input the student's name (first name last name): ");
		//Store the given name.
		name=kb.nextLine();
		
		//for loop to find the exact point where the first name ends (at the point where the user uses a space).
		for (int i=0; i<name.length(); i++)
		{
			if (name.charAt(i)==' ')
			{
				n=i;
			}
		}
		
		//For loop to run the length up to the space, and store those letters as the first name(fname).
		for (int i=0; i<n; i++)
		{
			fname+=name.charAt(i);
		}
		
		//For loop to run from the space to the end of the given name, store those letters as the last name(lname).
		for (int i=n; i<name.length(); i++)
		{
			lname+=name.charAt(i);
		}
		
		//Store the first name and last name into the KUStudent class.
		KUStudent one = new KUStudent();
		one.set_name(fname, lname);
		
		//Ask the user for the KUID and the department. Stored the input in ku variable.
		System.out.println("Please input the student's KUID and department: ");
		ku=kb.nextLine();
		
		//For loop to find the space, which is where the KUID ends and department input begins.
		for (int i=0; i<ku.length(); i++)
		{
			if (ku.charAt(i)==' ')
			{
				k=i;
			}
		}
		
		//For loop that runs up to the space.  Stores those characters as the KUID(kuid).
		for (int i=0; i<k; i++)
		{
			kuid+=ku.charAt(i);
		}
		
		//For loop that runs from the space to the end of the string KU. Stores those characters as the department(dpt).
		for (int i=k; i<ku.length(); i++)
		{
			dpt+=ku.charAt(i);
		}
		
		//Store the KUID and department into the KUStudent class.
		one.set_kuinfo(kuid, dpt);
		
		//Call method to print the information
		writeOutput(one);
		
		
	
	}
	
	//Method to take in a KUStudent input, and print the information stored in that object.
	public static void writeOutput(KUStudent stu)
	{
		System.out.println("Student: " + stu.get_fname() + stu.get_lname());
		System.out.println("KUID: " + stu.get_id());
		System.out.println("Department: " + stu.get_dpt());
	}

}
