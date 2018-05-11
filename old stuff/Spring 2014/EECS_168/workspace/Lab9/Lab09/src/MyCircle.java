
public class MyCircle 
{
	 //Define the constant PI.
    private final double PI = 3.141592;
    
    //The MyCircle class has one property: radius
    //Put a radius in your class
          public  double r=0.0;


    //The MyCircle class has methods too.
     
    //Make a method that calculates the diameter of a circle. Recall the radius is half of the diameter.
    //This method will take no parameters and return a double.
    //Why no parameters? Because the circle class has a radius built in. All methods in the Circle class have access to it without it being passed
    //as a parameter! Sweet!
            
            public double diameter()
            {
            	double diameter=2*r;
            	return(diameter);
            }




    //Make a method that returns the area of a Circle.
    //This method takes no parameters.  It returns a double.
    //Recall the area of a circle is PI * radius * radius
    //Since our circle has PI and radius as properties, we can use those in our function without passing them in as parameters. Tubular!

            public double area()
            {
            	double a=r*r*PI;
            	return (a);
            }
            
    

    //Make a method that returns the circumference of a Circle.
    //This method takes no parameters.  It returns a double.
    //Recall the circumference of a circle is 2 * PI * radius
    //Since our circle has PI and radius as properties, we can use those in our function without passing them in as parameters. Radical!
            
            public double circ()
            {
            	double c=2*PI*r;
            	return (c);
            }


}
