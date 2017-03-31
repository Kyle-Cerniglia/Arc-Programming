import java.util.ArrayList;
import java.util.Iterator;

public class arrayLists {
	
	public static void main(String []args){
		
		ArrayList listTest = new ArrayList();//Only used to store objects
		
		listTest.add("first item"); //String object
		listTest.add("second item");//Index number 1
		listTest.add("third item"); //Index number 2
		listTest.add(7);//Integer OBJECT, not an int data value
		
		listTest.get(2); //Gets object at index 2
		
		listTest.remove(2); //Removes index 2 or can use listTest.remove("second item"); resizes array
		
		Iterator it = listTest.iterator();//Iterator object to go through data in the List Array
		
		while( it.hasNext()){
			System.out.println(it.next());//it.hasNext will go false if there is no more object in list
			//Or can just print the list Array to do this syso(listTest);
		}
	}

}
