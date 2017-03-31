
public class semiprimeSolver {
	
	public static void main(String []args){
		
		double primeA = 499;
		double primeB = 947;
		double semiPrime = 4303187143.0; //2147483647
		double testA = 1;
		double testB = 2;
		double testTemp = 0;
		boolean loopBreak = false;
		double loop = 1;
		
		//semiPrime = primeA*primeB;//A
		
		for(loop = 1; loopBreak == false; loop++){//Loop 1
			testTemp = testA*testB;
			if( semiPrime == testTemp){//C
				loopBreak = true;//D
			}
			else{
				
				if(testA >= semiPrime){
					testB++;
					testA = 1;
				}
				else{
					testA++;//E
				}
			}
			System.out.println(testA + " " + testB);
		}//Loop 1

		
		System.out.println("Primes for " + semiPrime + ": " + testA + " " + testB);
		System.out.println("Number of operations: " + loop);
	}

}
