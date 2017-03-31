
public class operatorPrecedence {
	
	public static void main(String []args){
		// Other operators, && 'and', || 'or', == 'has the value of', ! 'not'
		short num1;
		short num2;
		short num3;
		double ans;
		
		num1 = 2;
		num2 = 5;
		num3 = 12;
		
		ans = num1 - num2 + num3 * num1; // Operates left to right following order of operations
		
		System.out.println(ans);
	}

}
