package dice;
import javax.swing.*;
import java.awt.Component;
import java.awt.event.*;
import javax.swing.JFrame;

public class main {

	
	private static void createAndDisplayGUI()
	{
		JFrame frame = new JFrame("Click counter");
		UserInput demo = new UserInput();
		//TextDemo demo1 = new TextDemo();
		
		frame.getContentPane().add( demo.getContent() );
		//frame.getContentPane().add( demo1.getContent() );
		
		frame.pack();
		frame.setVisible(true);
	}
	public static void main(String[] args)
	{
		createAndDisplayGUI();
	}
}
