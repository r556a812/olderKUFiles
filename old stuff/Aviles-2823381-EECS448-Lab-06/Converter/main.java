import javax.swing.JFrame;

public class main {
	
	private static void createAndDisplayGUI()
	{
		JFrame frame = new JFrame("Temperature Converter");
		Converter demo = new Converter();
		
		frame.getContentPane().add(demo.getContent());
		frame.pack();
		frame.setVisible(true);
	}
	
	public static void main(String[] args)
	{
		createAndDisplayGUI();
	}

}
