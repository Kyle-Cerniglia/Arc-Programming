
public class arrays {
	
	public static void main(String []args){
		
		int[] aryNums;// Defines an array integer var
		
		aryNums = new int[6];//Creats array object with 6 array positions from 0-5
		//Both lines could've been written as int[] aryNums = new int[6];		
		
		aryNums[0] = 10;//Declares that position 0 in the array will equal 10
		aryNums[1] = 14;
		aryNums[2] = 36;
		// Or you could've used int[] aryNums = {10,14,36}; to replace all of this
		
		String[] aryStrings = {"Fall","Spring","Summer","Winter"};//This is for string arrays
		
		boolean[] aryBools = new boolean[]{false, true, false, true};//For boolean arrays 'new boolean[]'
		
		System.out.println(aryNums[2]);//Prints value at position 2 in array aryNums
	}

}
