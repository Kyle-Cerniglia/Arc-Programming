
public class multiDimensionalArraySorting {
	
	public static void main(String []args){
		
		int[][] aryNumbers = new int [6][5];//6 is rows, 5 is columns
		
		int rows = 4;
		int columns = 2;
		
		int i, j;
		
		aryNumbers[2][1] = 4;
		aryNumbers[5][1] = 5;
		aryNumbers[9][2] = 2;
		aryNumbers[3][2] = 5;
		
		for( i = 0; i < rows; i++){//Holds inputs by row
			
			for( j = 0; j < columns; j++){//Holds inputs by column in the designated row
				System.out.print(aryNumbers[i][j] + " ");
			}
			System.out.println("");
		}
		}
	
}