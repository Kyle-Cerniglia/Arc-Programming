package lastDay;

import java.awt.event.*;

import javax.swing.*;

public class Interfaces implements ActionListener{ 
	static JFrame f = new JFrame();
	
	JButton b = new JButton("temporary");//JButton is the var description
	static int x;//'static' opens 'x' to all the classes
	String stringing = "You've clicked " + x + " times.";
	
	public static void main(String args[]){//Method main, has to be static to define the start
		Interfaces gui = new Interfaces(); //Creates object of 'Interfaces gui'
		
		f.setSize(300, 300);//TODO, this shows a checkmark on the left
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
		
		gui.go();//calls the 'go' method
	}
	public void go(){//creates method 'go'
		f.add(b);//adds button
		
	}
	@Override //Has priority
	public void actionPerformed(ActionEvent e) {//replaced args with'e'(STD)
		x++;
		stringing = "You've clicked" + x + " times.";
		b.setText(stringing);//Displays the text onto the button.	
	}
}
