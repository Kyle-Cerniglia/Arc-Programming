import javax.swing.JOptionPane;
import java.util.Arrays;

public class numberMode {
	
	public static void main(String []args){
		
		String dataArraySizes;
		int dataArraySize = 0;
		int inputLoop = 0;
		int inputLoopWindow = 0;
		String inputTemps;
		double inputTemp = 0;
		boolean endMode = false;
		int positionTemp = 0;
		double positionTest = 0;
		int currentPosition = 0;
		int solveLoop = 0;
		double maxData = 0;
		int solveLoopTemp = 0;
		int algoTemp = 0;
		double algoCalcTemp = 0;
		int algoLocTemp = 0;
		int locSize = 0;
		int locPosition = 0;
		
		//Stores number of data points
		dataArraySizes = JOptionPane.showInputDialog("Number of data values", "Enter number here");
		dataArraySize = Integer.parseInt(dataArraySizes);
		
		//Creates array object
		double[] dataArray = new double[dataArraySize];
		
		//Loads data into array
		for(inputLoop = 0; inputLoop < dataArray.length; inputLoop++){
			inputLoopWindow = inputLoop + 1;
			inputTemps = JOptionPane.showInputDialog("Data value " + inputLoopWindow, "Enter value here");
			inputTemp = Double.parseDouble(inputTemps);
			dataArray[inputLoop] = inputTemp;
		}
		//Sorts data
		Arrays.sort(dataArray);
		
		double[][] sortingArray = new double [dataArraySize][2];
		
		//From here, compare the first value with itself and count how many times it sees itself,
		//then write that into a 2Xx array with the stored testing value and the quantity of times it
		//is found. Then sort the quantity column and take the value associated with that quantity.
		//Need to then identify multiple modes.
		
		/*
		
		//Identifies largest data value
		maxData = dataArray[dataArray.length];
		//Creates array for algorithm processing on the data array
		double[] algoArray = new double[dataArray.length];
		
		int[] locArray = new int[locSize];
		
		solveLoopTemp = solveLoop -1;
		//Stores the 
		for(solveLoop = 0; solveLoop < dataArray.length ; solveLoop++){
			algoCalcTemp = dataArray[algoTemp] / dataArray[solveLoopTemp + 1];
			if( algoCalcTemp == 1){
				algoArray[algoTemp]++;
			}
			else{
				locArray[locPosition] = 
			}
			*/
		}
		
	}


