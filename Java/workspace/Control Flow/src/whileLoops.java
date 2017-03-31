
public class whileLoops {
	
	public static void main(String []args){
		
		int loopVal = 0;
		
		while(loopVal < 5){//Loops while condition is met, can make permanent condition for infinite loop
			System.out.println("Printing some text");
			loopVal++;
		}
		do{// Do whiles execute code atleast once even if the conditions are met
			System.out.println("Printing moar text");
			loopVal++;
		}
		while(loopVal < 5);
	}

}
