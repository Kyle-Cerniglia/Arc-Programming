

import java.util.Scanner;

public class GameWorks {
	int guess;
	int number = (int) Math.floor(Math.random()*100);
	int hintcounter = 0;
	public boolean won = false;
	public void gatherGuess() {
		System.out.println("Input guess:");
		
		Scanner gatherer = new Scanner(System.in);
		guess = gatherer.nextInt();
	}
	public void whereIsIt(){
		if(guess > number){
			System.out.println("Wrong, you are too high.");
		}
		else {
		}
		if(guess < number){
			System.out.println("Wrong, you are too low.");
		}
		else{
		}
		}
	public int hintdetermine () { //this is a method, not just a variable
		int hint = (int) (Math.floor(number / 10)) * 10; //Rounds to nearest 10's
		return hint;//If the method is NOT VOID, it returns this
	}
	public void guessCorrect(int guess) {
		if(guess == number) {
			System.out.println("You've got the number! It was " + number);
			won = true;
		} else {
			if(hintcounter == 3){
			hintcounter = 0;
			System.out.println("Try again (Hint: The Number is between " + hintdetermine() + " and " + (hintdetermine() + 10));
			}
			else {
				hintcounter++;
			}
		}
	}
}
