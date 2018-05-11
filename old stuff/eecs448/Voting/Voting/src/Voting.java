import javax.swing.*;
import java.awt.event.*;
import java.awt.Component;
import java.awt.GridLayout;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.io.File;

public class Voting {
	
	private JPanel panel;
	private JPanel panel2;
	private JButton vote1;
	private JButton vote2;
	private JButton vote3;
	private JButton vote4;
	private JTextField first;
	private JTextField last;
	private JLabel label;
	String writeFile = "LastName_FirstName_ballot.txt";
	
	
	
	
	
	public Voting()
	{
		panel = new JPanel();
		vote1 = new JButton("Me");
		vote2 = new JButton("You");
		vote3 = new JButton("Him");
		vote4 = new JButton("Her");
		first = new JTextField(3);//3 cols, not 20 chars
		last = new JTextField(3);//3 cols, not 20 chars
		label = new JLabel("Enter First and Last Name, then select candidate of choice");
		
		//Load the listener
		vote1.addActionListener(vote1Listener());
		vote2.addActionListener(vote2Listener());
		vote3.addActionListener(vote3Listener());
		vote4.addActionListener(vote4Listener());
		
		//load the panel
		panel.add(first);
		panel.add(last);
		panel.add(vote1);
		panel.add(vote2);
		panel.add(vote3);
		panel.add(vote4);
		panel.add(label);
	}
	
	public Component getContent()
	{
		return (panel);
	}
	
	private ActionListener vote1Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent evt)
			{
				
				String inputFirst = first.getText();
				String inputLast = last.getText();
				String vote = "ME";
				try {
					File file = new File(writeFile);
					FileOutputStream ostr = new FileOutputStream(file);
					OutputStreamWriter owtr = new OutputStreamWriter(ostr);
					owtr.write(inputFirst + " " + inputLast + " " + vote, 0, inputFirst.length() + inputLast.length() + vote.length());
					owtr.close();
					
					System.out.println(inputFirst + " " + inputLast + " " + vote);
				} 
				catch (IOException ex) {
					System.out.println(ex.getMessage());
				}
			}
		};
		
		return listener;
	}
	
	private ActionListener vote2Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String inputFirst = first.getText();
				String inputLast = last.getText();
				String vote = "YOU";
				try {
					File file = new File(writeFile);
					FileOutputStream ostr = new FileOutputStream(file);
					OutputStreamWriter owtr = new OutputStreamWriter(ostr);
					owtr.write(inputFirst + " " + inputLast + " " + vote, 0, inputFirst.length() + inputLast.length() + vote.length());
					owtr.close();
					
					System.out.println(inputFirst + " " + inputLast + " " + vote);
				} 
				catch (IOException ex) {
					System.out.println(ex.getMessage());
				}
			}
		};
		
		return listener;
	}
	
	private ActionListener vote3Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String inputFirst = first.getText();
				String inputLast = last.getText();
				String vote = "HIM";
				try {
					File file = new File(writeFile);
					FileOutputStream ostr = new FileOutputStream(file);
					OutputStreamWriter owtr = new OutputStreamWriter(ostr);
					owtr.write(inputFirst + " " + inputLast + " " + vote, 0, inputFirst.length() + inputLast.length() + vote.length());
					owtr.close();
					
					System.out.println(inputFirst + " " + inputLast + " " + vote);
				} 
				catch (IOException ex) {
					System.out.println(ex.getMessage());
				}
				
			}
		};
		
		return listener;
	}
	
	private ActionListener vote4Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String inputFirst = first.getText();
				String inputLast = last.getText();
				String vote = "HER";
				try {
					File file = new File(writeFile);
					FileOutputStream ostr = new FileOutputStream(file);
					OutputStreamWriter owtr = new OutputStreamWriter(ostr);
					owtr.write(inputFirst + " " + inputLast + " " + vote, 0, inputFirst.length() + inputLast.length() + vote.length());
					owtr.close();
					
					System.out.println(inputFirst + " " + inputLast + " " + vote);
				} 
				catch (IOException ex) {
					System.out.println(ex.getMessage());
				}
			}
		};
		
		return listener;
	}
}
	