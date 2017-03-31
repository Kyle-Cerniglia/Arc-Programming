import java.util.Scanner;
import javax.swing.JOptionPane; // Popup boxes
import javax.swing.JOptionPane;
//import javax.swing.JOptionPane;
public class optionPanes {
	
	public static void main(String []args){
		
		String full_name;
		String family_name;
		String first_name;
		String side1;
		String side2;
		int area;
		
		first_name = JOptionPane.showInputDialog("First name", "Enter your first name"); 
		// Creates input dialog box with var data, 2nd statement puts words in text box as default
		family_name = JOptionPane.showInputDialog("Family name", "Enter your family name");
		// 'Family name' stated above input field
		
		full_name = "You are " + first_name + " " + family_name;
		
		JOptionPane.showMessageDialog(null, full_name, "Name", JOptionPane.INFORMATION_MESSAGE); 
		// Displays var data in a box, "Name" names the head of the box
		// INFORMATION, ERROR, PLAIN, QUESTION, or WARNING can be used before _MESSAGE, if not, its ?
		
		side1 = JOptionPane.showInputDialog("Side 1", "Enter the first side");
		side2 = JOptionPane.showInputDialog("Side 2", "Enter the second side");
		
		area = Integer.parseInt(side1) * Integer.parseInt(side2);
		// Integer.parseInt() converts numeric string var's into int var's
		// Can replace the 'Integer' part with 'float' for example
		
		JOptionPane.showMessageDialog(null, area, "Area", JOptionPane.PLAIN_MESSAGE);
		System.exit(0); // Returns a 0 to Java making sure the program terminated and deletes any objects
	}

}
