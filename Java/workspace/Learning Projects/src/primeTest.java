
public class primeTest {
	
	public static void main(String []args){
		
		double testVar = 100;//A
		double varDivide = 2;
		double varDivideFinal = 0;
		int varCount = 0;
		double highestPrime = 1;
		int loopCount = 0;
		int loopCount2 = 0;
		boolean forExit = false;
		boolean lock = false;
		
		//for(loopCount2 = 0; lock == false; loopCount2++){
		
		for(loopCount = 0; forExit == false; loopCount++){
			
			varDivideFinal = testVar / varDivide;//B
			
			if(varDivideFinal == (int)varDivideFinal){//C
				
				if(testVar == varDivide){//D
					forExit = true;
					highestPrime = testVar;
					System.out.println("Prime");
					//System.out.println(highestPrime);
				}
				else{//F
					forExit = true;
					System.out.println("Not Prime");
					
				}
				
			}
			else{//E
				varDivide++;
				
				if(testVar < varDivide){
					forExit = true;
					System.out.println("Prime");
				}
				else{//I
					
				}
			}
		
		}//for 2
		forExit = false;
		testVar++;
		varDivide = 2;
		//}//for 1
		
	}

}
