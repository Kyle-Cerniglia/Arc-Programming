import java.util.Scanner;

public class userInput {
	
	public static void main(String []args){
		
		String first_name;
		String family_name;
		Scanner user_input = new Scanner(System.in); // Creates and defines 'Scanner' var as 'user_input'
		// 'new' created a new object within the 'Scanner' class, in parenthasis tells Java that we will
		// be inputing data.
		
		System.out.print("Enter your name here: ");
		first_name = user_input.next(); // 'next' defines the next string typed by the user
		
		System.out.print("Enter your last name here: ");
		family_name = user_input.next();
		
		System.out.println(first_name + " " + family_name);
	}

}
