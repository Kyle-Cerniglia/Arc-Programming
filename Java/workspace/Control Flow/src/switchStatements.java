
public class switchStatements {
	
	public static void main(String []args){// Condensed for of if else if statements
		
		short user = 18;
		String name = "Kyle";
		
		switch (user){
		case 18:
			System.out.println("UR 18");
			break;// Breaks the case
			
		case 19:
			System.out.println("UR 19");
			break;
			
		case 20:
			System.out.println("UR 20");
			break;
		
		default:
			System.out.println("UR not 18, 19, or 20"); //Default option is optional
		}
		
		if( name.equals("Kyle")){  // Compares if a string is the same as another string
			System.out.println("Hi me!");
		}
	}

}
