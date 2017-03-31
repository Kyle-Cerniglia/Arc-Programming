import java.util.Scanner;

import javax.swing.JOptionPane;


public class dadOpenThis {
	public static void main(String args[]){

		int correctNumber;
		String testNumber;
		int testNumberI;
		int placeholder;

		correctNumber = 7590;
		testNumberI = 0;
		for( placeholder = 0; testNumberI != correctNumber; placeholder++){

		testNumber = JOptionPane.showInputDialog("Once you discover the code, you may enter it here to find your final clue. This is your first clue: There is another device, while ancient and modern at the same time, is very close and contains a 'bit' of the code.", "Enter your code here");

		testNumberI = Integer.parseInt(testNumber);

		if(testNumberI == correctNumber){

			JOptionPane.showMessageDialog(null,"You're correct! Your christmas should 'go off with a bang'.", "Correct", JOptionPane.PLAIN_MESSAGE);

		}
		else{
			JOptionPane.showMessageDialog(null,"Try again!", "Incorrect", JOptionPane.ERROR_MESSAGE);
		}
		}

		System.exit(0);

	}

}
