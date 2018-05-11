/* -----------------------------------------------------------------------------
 *
 * File Name:  ConvertTemperature.java
 * Author: Richard Aviles
 * Assignment:   EECS-168/169 Lab 2
 * Description:  This program will convert the input temperature from Fahrenheit to Celsius.
 * Date: 02/04/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;

public class ConvertTemperature 
{
	public static void main(String[] args)
	{
	
	//Create a scanner object.
	Scanner input = new Scanner(System.in);
	
	//Declare the variables and constants.
	double Fahrenheit;
	double Celsius;
	
	System.out.println("Enter the temperature in Fahrenheit:");
	
	//Read the input from the keyboard.
	Fahrenheit = input.nextDouble();
	
	//Calculate the conversion.
	Celsius = (Fahrenheit-32)*5/9;
			
			System.out.println("*Conversion:" );
	System.out.println(Fahrenheit + " degrees Fahrenheit = " + Celsius + " degrees Celsius.");
}
	
	
	

}
