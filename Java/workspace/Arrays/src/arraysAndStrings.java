import java.util.Arrays;

public class arraysAndStrings {
	
	public static void main(String []args){
		
		int i;
		String[] aryString = new String[5];
		
		aryString[0] = "This";
		aryString[1] = "is";
		aryString[2] = "a";
		aryString[3] = "string";
		aryString[4] = "array";
		
		Arrays.sort(aryString);//Sorts alphabetically, caps before lowercase
		
		for( i=0; i < aryString.length; i++){
			System.out.println(aryString[i]);
		}
	}

}
