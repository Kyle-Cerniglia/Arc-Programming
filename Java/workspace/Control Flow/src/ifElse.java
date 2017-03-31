import java.util.Scanner;
import javax.swing.JOptionPane;

public class ifElse {
	
	public static void main(String []args){// Else If's can be used between an If and an Else statement
		
		String users;
		int user;
		
		users = JOptionPane.showInputDialog("Age", "Enter your age");
		
		user = Integer.parseInt(users);
		
		if(user >= 100 && user < 999){
			JOptionPane.showMessageDialog(null, "Too old to count!", "Period of life", JOptionPane.PLAIN_MESSAGE);
		}
		else if(user >= 75){
			JOptionPane.showMessageDialog(null, "You're over the hill!", "Period of life", JOptionPane.PLAIN_MESSAGE);
		}
		else if(user >= 50){
			JOptionPane.showMessageDialog(null, "Half a hundred!", "Period of life", JOptionPane.PLAIN_MESSAGE);
		}
		else if(user >= 30){
			JOptionPane.showMessageDialog(null, "Young adult", "Period of life", JOptionPane.PLAIN_MESSAGE);
		}
		else if(user >= 18){
			JOptionPane.showMessageDialog(null, "College student", "Period of life", JOptionPane.PLAIN_MESSAGE);
		}
		else if(user >= 13){
			JOptionPane.showMessageDialog(null, "Teenager", "Period of life", JOptionPane.PLAIN_MESSAGE);
		}
		else if(user >= 5){
			JOptionPane.showMessageDialog(null, "Kid", "Period of life", JOptionPane.PLAIN_MESSAGE);
		}
		else if(user >= 2){
			JOptionPane.showMessageDialog(null, "Toddler", "Period of life", JOptionPane.PLAIN_MESSAGE);
		}
		else{
			JOptionPane.showMessageDialog(null, "Baby", "Period of life", JOptionPane.PLAIN_MESSAGE);
		}
	}

}
