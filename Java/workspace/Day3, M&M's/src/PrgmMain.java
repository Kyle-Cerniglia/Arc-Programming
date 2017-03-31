

public class PrgmMain {
	public static void main (String args[]) {
		System.out.println("Welcome to Guess100");
		
		GameWorks G = new GameWorks(); //Creates the object G as the GameWorks Class
		while(G.won != true) { //G. references the G object
			G.gatherGuess();
			G.guessCorrect(G.guess);
			G.whereIsIt();
		}	

	}

}
