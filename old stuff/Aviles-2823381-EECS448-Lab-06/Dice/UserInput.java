package dice;
import javax.swing.*;
import java.awt.event.*;
import java.awt.Component;
import java.awt.GridLayout;
import java.util.*;

public class UserInput {
	
	private JPanel panel;
	private JButton button;
	private JTextField text;
	private JLabel label;
	
	public UserInput()
	{
		panel = new JPanel();
		button = new JButton("RollDice");
		text = new JTextField(3);
		label = new JLabel("Enter A Number of Sides");
		
		
		//Load the listener
		button.addActionListener(buttonListener());	
		
		//load the panel
		panel.add(text);
		panel.add(button);
		panel.add(label);
	}
	
	public Component getContent()
	{
		return (panel);
	}
	
	private ActionListener buttonListener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				Random roll = new Random();
				String input = text.getText();
				int numSides = Integer.parseInt(input);
				int amount = roll.nextInt(numSides); 
				
				String newText = Integer.toString(amount);
				label.setText(newText);
				System.out.println(newText);
			}
		};
		
		return listener;
	}	

}
