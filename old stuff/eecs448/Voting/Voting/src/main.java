import javax.swing.JFrame;

public class main {
	
	private static void createAndDisplayGUI()
	{
		JFrame frame = new JFrame("Voting");
		Voting demo = new Voting();
		
		frame.getContentPane().add(demo.getContent());
		frame.pack();
		frame.setVisible(true);
	}
	
	public static void main(String[] args)
	{
		createAndDisplayGUI();
	}

}
