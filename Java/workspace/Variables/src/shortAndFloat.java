
public class shortAndFloat {
	
	public static void main(String []args){
		
		short num1; // 'int' var between -32768 and 32767
		float num2; // Normal 'float' var is a 32 bit number, the 'double' var is 64 bit
		float ans;
		
		num1 = 5;
		num2 = 2.5f; // The 'f' is needed to distinguish between a 'double' and a 'float'
		
		ans = num1 / num2;
		
		System.out.println(ans);
	}

}
