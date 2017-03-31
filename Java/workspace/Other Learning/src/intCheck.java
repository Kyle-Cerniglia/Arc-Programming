
public class intCheck {
	
	public static void main(String []args){
		
		double testVar = 0;
		double num1 = 5;
		double num2 = 2;
		
		testVar = num1 / num2;
		
		System.out.println(testVar);
		//if ((testVar == Math.floor(testVar)) && !Double.isInfinite(testVar)){ // alternate form
		if(testVar == (int)testVar){ //Checks to see it the value is an integer
			System.out.println("Whole");
		}
		else{
			System.out.println("Not Whole");
		}
	}

}
