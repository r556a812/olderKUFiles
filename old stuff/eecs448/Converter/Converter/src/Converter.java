import javax.swing.*;
import java.awt.event.*;
import java.awt.Component;
import java.awt.GridLayout;

public class Converter {

	
	private JPanel panel;
	private JButton FtoC;
	private JButton FtoK;
	private JButton CtoK;
	private JButton CtoF;
	private JButton KtoF;
	private JButton KtoC;
	private JTextField text;
	private JLabel label;
	
	public Converter()
	{
		panel = new JPanel();
		FtoC = new JButton("F to C");
		FtoK = new JButton("F to K");
		CtoK = new JButton("C to K");
		CtoF = new JButton("C to F");
		KtoF = new JButton("K to F");
		KtoC = new JButton("K to C");
		text = new JTextField(3);//3 cols, not 20 chars
		label = new JLabel("Enter a temperature");
		
		//Load the listener
		FtoC.addActionListener(FtoCListener());
		FtoK.addActionListener(FtoKListener());
		CtoK.addActionListener(CtoKListener());
		CtoF.addActionListener(CtoFListener());
		KtoF.addActionListener(KtoFListener());
		KtoC.addActionListener(KtoCListener());
		
		//load the panel
		panel.add(text);
		panel.add(FtoC);
		panel.add(FtoK);
		panel.add(CtoK);
		panel.add(CtoF);
		panel.add(KtoF);
		panel.add(KtoC);
		panel.add(label);
	}
	
	public Component getContent()
	{
		return (panel);
	}
	
	private ActionListener FtoCListener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent evt)
			{
				boolean valid = false;
				
				while (!valid) {
				    try {
				        String input = text.getText();
				        double tempInF = Double.parseDouble(input);//convert String to double
				        double tempInC = (tempInF-32)*(5.0/9.0); //convert F to C
				        String newText = "Temp in C: " + String.format("%.2f",tempInC);//convert double to String and
											       //only display 2 places past decimal
				        label.setText(newText);
				        System.out.println(newText);
				        valid = true;
			
				    } catch (NumberFormatException e) {
				    	//error
				    	JOptionPane.showMessageDialog(null,"Error, not a number. Please try again.");
				    	
				    }
				}
			}
		};
		
		return listener;
	}	
	
	private ActionListener FtoKListener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent evt)
			{
				boolean valid = false;
				
				while(!valid) {
					try {
						String input = text.getText();
						double tempInF = Double.parseDouble(input);//convert String to double
						double tempInK = ((tempInF-32)*(5.0/9.0)) + 273.15; //convert F to C
						String newText = "Temp in K: " + String.format("%.2f",tempInK);//convert double to String and
													       //only display 2 places past decimal
						label.setText(newText);
						System.out.println(newText);
						valid = true;
					}catch (NumberFormatException e) {
						//error
				    	JOptionPane.showMessageDialog(null,"Error, not a number. Please try again.");
					}
				}
			}
		};
		
		return listener;
	}	
	
	private ActionListener CtoKListener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent evt)
			{
				boolean valid = false;
				
				while (!valid) {
					try {
						String input = text.getText();
						double tempInC = Double.parseDouble(input);//convert String to double
						double tempInK = tempInC + 273.15; //convert F to C
						String newText = "Temp in K: " + String.format("%.2f",tempInK);//convert double to String and
													       //only display 2 places past decimal
						label.setText(newText);
						System.out.println(newText);
						valid = true;
					}catch (NumberFormatException e) {
						//error
				    	JOptionPane.showMessageDialog(null,"Error, not a number. Please try again.");
					}
				}
			}
		};
		
		return listener;
	}	
	
	private ActionListener CtoFListener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent evt)
			{
				boolean valid = false;
				
				while (!valid) {
					try {
						String input = text.getText();
						double tempInC = Double.parseDouble(input);//convert String to double
						double tempInF = (tempInC *(9/5)) + 32; //convert F to C
						String newText = "Temp in F: " + String.format("%.2f",tempInF);//convert double to String and
													       //only display 2 places past decimal
						label.setText(newText);
						System.out.println(newText);
						valid = true;
					}catch ( NumberFormatException e) {
						//error
				    	JOptionPane.showMessageDialog(null,"Error, not a number. Please try again.");
					}
				}
			}
		};
		
		return listener;
	}	
	
	private ActionListener KtoFListener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent evt)
			{
				boolean valid = false;
				
				while (!valid) {
					try {
						String input = text.getText();
						double tempInK = Double.parseDouble(input);//convert String to double
						double tempInF = ((tempInK-273.15)*(9.0/5.0)) + 32; //convert F to C
						String newText = "Temp in F: " + String.format("%.2f",tempInF);//convert double to String and
													       //only display 2 places past decimal
						label.setText(newText);
						System.out.println(newText);
						valid = true;
					}catch (NumberFormatException e) {
						//error
				    	JOptionPane.showMessageDialog(null,"Error, not a number. Please try again.");
					}
				}
			}
		};
		
		return listener;
	}	
	
	private ActionListener KtoCListener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent evt)
			{
				boolean valid = false;
				
				while (!valid) {
					try {
						String input = text.getText();
						double tempInK = Double.parseDouble(input);//convert String to double
						double tempInC = tempInK-273.15; //convert F to C
						String newText = "Temp in C: " + String.format("%.2f",tempInC);//convert double to String and
													       //only display 2 places past decimal
						label.setText(newText);
						System.out.println(newText);
						valid = true;
					}catch (NumberFormatException e) {
						//error
				    	JOptionPane.showMessageDialog(null,"Error, not a number. Please try again.");
					}
				}
			}
		};
		
		return listener;
	}	
}
