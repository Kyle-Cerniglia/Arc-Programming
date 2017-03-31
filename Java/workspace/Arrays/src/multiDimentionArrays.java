
public class multiDimentionArrays {
	
	public static void main(String []args){
		
		int[][] aryNumbers = new int [6][5];//6 is rows, 5 is columns
		
		int rows = 6;
		int columns = 5;
		
		int i, j;
		
		aryNumbers[5][2] = 4; //Defines point (6,3) as being 4
				
		for( i = 0; i < rows; i++){//Holds inputs by row
			
			for( j = 0; j < columns; j++){//Holds inputs by column in the designated row
				System.out.print(aryNumbers[i][j] + " ");
			}
			System.out.println("");//Shifts to next line after filling out a row
		}
		
	}

}
