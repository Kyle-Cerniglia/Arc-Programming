
public class forLoops {
	
	public static void main(String []args){
		
		int remainder;
		int total = 10;
		short loopVal;
		short end_value = 11;
		
		for (loopVal = 0; loopVal < end_value; loopVal++){//(begin value; end value [loop until false]; 
														  //increment value)
			System.out.println("Loop value = " + loopVal);
			
		}
		remainder = total %3;// % is the modulus or remainder solver, use int var's
		System.out.println(remainder);
		
	}

}
