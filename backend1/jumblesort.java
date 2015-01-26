import java.util.*;

public class jumblesort
{

  public static void main(String[] args)
  {
    /*
    These arrays will hold
      Vector of strings from stdin
      Vector of ints from stdin
      the datatype originally at each index of the inputed array
    */
    PriorityQueue<String> stringsFromInput = new PriorityQueue<String>();
    PriorityQueue<Integer> intsFromInput = new PriorityQueue<Integer>();
    boolean[] datatypeAtIndexIsInt = new boolean[args.length];

    /*
    Now we run through the original Vector, processing each string or int into
    its respective array and storing the data type at that index in the third
    array
    Costs O(n)
    */
    for(int i = 0; i < args.length; i++)
    {
      int value;
      try{
        //Rudimentary check if value is an integer
        value = Integer.parseInt(args[i]);
        //If no exception thrown, it was and we can add it to the int Vector
        //Also flip bit in datatype array to signal this index was an int
        intsFromInput.add(value);
        datatypeAtIndexIsInt[i] = true;
      }
      catch(NumberFormatException ex)
      {
        stringsFromInput.add(args[i]);
      }
    }

    StringBuilder jumbleSortedString = new StringBuilder();
    // int intCounter = 0;
    // int stringCounter = 0;
    for(int i = 0; i < datatypeAtIndexIsInt.length; i++)
    {
      if(datatypeAtIndexIsInt[i])
      {
        jumbleSortedString.append(intsFromInput.poll() + " ");
        // intCounter++;
      }
      else
      {
        jumbleSortedString.append(stringsFromInput.poll() + " ");
        // stringCounter++;
      }
    }
    System.out.println(jumbleSortedString);

  }
}
