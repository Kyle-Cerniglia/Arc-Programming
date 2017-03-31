import javax.swing.JOptionPane;

public class numberAverage {
	
	public static void main(String []args){
		
		String nums;
		double num = 0;
		int loopCount = 0;
		int displayCount = 0;
		double avgAdd = 0;
		double avg = 0;
		String currentNums;
		double currentNum = 0;
		boolean loop = true;
		
		while(loop = true){
		//Stores number of data points
		nums = JOptionPane.showInputDialog("Number of data values", "Enter number here");
		num = Double.parseDouble(nums);
		
		//Accepts data and adds them
		for(loopCount = 0; loopCount < num; loopCount++){
			displayCount = loopCount + 1;
			currentNums = JOptionPane.showInputDialog("Data value " + displayCount, "Enter value here");
			currentNum = Double.parseDouble(currentNums);
			avgAdd = currentNum + avgAdd;
		}
		//Takes average of data
		avg = avgAdd / num;
		//Displays data
		JOptionPane.showMessageDialog(null, avg, "Average", JOptionPane.PLAIN_MESSAGE);
		}
	}
	
}