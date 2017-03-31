package animations;

import javax.swing.*; // The '*' means it takes in all subclasses under swing.

public class Frames {
	public static void main(String[] args){
		JFrame frame = new JFrame(); // Creats frame
		frame.setTitle("window"); // Titles frame as 'window'
		frame.setSize(600,400); // Coords in pixels
		frame.setVisible(true); // Makes the frame visible
		frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE); // Stops program
	}
	
}
