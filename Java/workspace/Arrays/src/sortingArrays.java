import java.util.Arrays;
import java.util.Collections;

public class sortingArrays {
	
	public static void main(String []args){
		
		int a;
		int[] aryNums;
		aryNums = new int[6];
		
		aryNums[0] = 10;
		aryNums[1] = 14;
		aryNums[2] = 36;
		aryNums[3] = 27;
		aryNums[4] = 43;
		aryNums[5] = 18;
		
		Arrays.sort(aryNums);// From the imported library, sorts code into ascending value order
		
		for (a=0; a < aryNums.length; a++){
			System.out.println("Num: " + aryNums[a]);
		}
		//For descending order
		Integer[] integerArray = new Integer[aryNums.length];//Created int object array for loop counting
		
		for (int i = 0; i < aryNums.length; i++){//Moves values from aryNums to the new array
			integerArray[i] = new Integer(aryNums[i]); 
		}
		Arrays.sort(integerArray, Collections.reverseOrder() );//Sorts in descending order
		
		for (int i = 0; i < integerArray.length; i++){//Display results
			System.out.println("Num; " + integerArray[i]);
		}
		
		
	}

}
