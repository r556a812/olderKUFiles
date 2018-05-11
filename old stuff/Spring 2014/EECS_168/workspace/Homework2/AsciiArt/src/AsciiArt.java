import java.util.Scanner;

public class AsciiArt 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		//Declare vairables.
		int pattern=0;
		int x;
		
		//Do-while statement to get the user to enter a number that corresponds to a selection choice for the patterns.
		do
		{
		System.out.print("Choose one of the following patterns by typing the corresponding number:\n1) Stripes\n2) Checker Board\n3) Double Diagnal\n4) Two Islands\n ");
		pattern = input.nextInt();
		if (pattern<=0)
		{
			System.out.print("Error \n");
		}
		if (pattern>4)
		{
			System.out.print("Error \n");
		}
		}while (!(pattern<=4 && pattern>0));
		
		//Do-while statement to make sure the user asks for a size bigger than 1.
		do
		{
		System.out.print("Input a size (Must be larger than 1): \n");
		x=input.nextInt();
		if (x<=0)
		{
			System.out.print("Error \n");
		}
		}while(!(x>1));
		
		//Pattern 1 design
		if (pattern==1)
		{
			for (int o=1; o<=x; o=o+1)
			{
				System.out.print(o-1);
				for (int i=1; i<=x; i=i+1)
				{
					if (i%2 == 0)
					{
						System.out.print(" ");
					}
					if (i%2 == 1)
					{
						System.out.print("*");
					}
				}
				System.out.print("\n");
			}
		}
		
		//Pattern 2 design
		if (pattern==2)
		{
			for(int oc=1; oc<=x; oc=oc+1)
			{
				System.out.print(oc-1);
				for (int ic=1; ic<=x; ic=ic+1)
				{
					if ((oc+ic)%2==0)
					{
						System.out.print("*");
					}
					if ((oc+ic)%2==1)
					{
						System.out.print(" ");
					}

				}
				System.out.print("\n");
			}
		}
		
		//Pattern 3 design
		if(pattern==3)
		{
			int dd=x;

			for(int od=1; od<=x; od=od+1)
			{
				System.out.print(od-1);
				for (int id=1; id<=x; id=id+1)
				{
					if(id==dd)
					{
						System.out.print("*");
					}
					else if (id==od)
					{
						System.out.print("*");
					}
					
					else if (id!=dd)
					{
						System.out.print(" ");
					}
					

				}
				dd=dd-1;
				System.out.print("\n");
			}
		}
		
		//Pattern 4 design
		if (pattern==4)
		{
			int aa=x;

			for(int ot=1; ot<=x; ot=ot+1)
			{
				System.out.print(ot-1);
				for (int it=1; it<=x; it=it+1)
				{
					
					if(it==aa)
					{
						System.out.print("*");
					}
					else if (ot/2==0)
					{
						System.out.print("!");
					}
					else if (aa/2==0)
					{
						System.out.print("?");
					}
				
					else if (it!=aa)
					{
						System.out.print("~");
					}
					
				}
				
				aa=aa-1;
				System.out.print("\n");
			}
		}
					

	}
}
