
public class wait {
	
	public static void main(String []args){
		
		short loopVal;
		short end_value = 11;
		
		for (loopVal = 0; loopVal < end_value; loopVal++){ //  (begin value; end value; increment value)
			
			System.out.println("Loop value = " + loopVal);
			
			try{
				Thread.sleep(500); //Sleeps thread for 500 ms
			} 
			catch(InterruptedException ex){ //Finds the thread interruption
				Thread.currentThread().interrupt(); // Restarts the thread
			}
			
		}
		
	}

}



