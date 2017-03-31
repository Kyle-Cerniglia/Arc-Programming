
public class arraysAndLoops {
	
	public static void main(String []args){
		
		int[] lottery_numbers = new int[49];
		int i;
		
		for (i=0; i < lottery_numbers.length; i++){// .length addresses the # of positions in an array
			lottery_numbers[i] = i + 1;//Function to assign ticket values to the correct position
			System.out.println(lottery_numbers[i]);
		}
	}
	

}
