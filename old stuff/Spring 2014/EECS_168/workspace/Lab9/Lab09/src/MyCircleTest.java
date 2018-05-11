
public class MyCircleTest 
{
	public static void main(String[] args) 
	{
		
        // Declare a new circle called myCircle
		MyCircle myCircle= new MyCircle();
		
		
        
        //Assign the radius a value of 5.5
       myCircle.r=5.5;
       
        //Display a message to the screen that says "My circle has a radius of <put the radius here>"
       
       System.out.println("My circle has a radius of "+myCircle.r);

        //Declare two doubles, theArea and theCircum
       double theArea=0.0;
       double theCircum=0.0;

        //Use the method area() from myCircle to store the area in theArea   
       theArea=myCircle.area();

        //Use the method circumference() from myCircle to store the circumference in theCircum
       theCircum=myCircle.circ();

        //Display a message to the screen "The area is <put the area here>"
       System.out.println("The area is "+theArea);

        //Display a message to the screen "The circumference is <put the circumference here>"
       System.out.println("The circumference is "+theCircum);

        //Using only a method call to diameter(), write a message to the screen "The diameter is <put the diameter here>"
       System.out.println("The diameter is "+myCircle.diameter());
}


}
