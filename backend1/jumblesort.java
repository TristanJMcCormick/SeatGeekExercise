import java.util.*;

public class jumblesort
{
  public static void main(String[] args)
  {
    //11 -1 4 Michael William 12 Richard Dennis 3
    /*
    These arrays will hold
    Vector of strings from stdin
    Vector of ints from stdin
    the datatype originally at each index of the inputed array
    */
    Vector stringsFromInput = new Vector(0);
    Vector intsFromInput = new Vector(0);
    boolean[] datatypeAtIndex = new boolean[args.length];

    /*
    Now we run through the original Vector, processing each string or int into
    its respective array and storing the data type at that index in the third
    array
    */
    for(int i = 0; i < args.length; i++)
    {
      int value;
      try{
        //Rudimentary check if value is an integer
        value = Integer.parseInt(args[i]);
        //If no exception thrown, it was and we can add it to the int Vector
        //Also flip bit in datatype array to signal this index was an int
        System.out.println("Int, adding to int array.");
        intsFromInput.addElement(value);
        datatypeAtIndex[i] = true;
      }
      catch(java.lang.NumberFormatException ex)
      {
        System.out.println("Not an int, adding to string array.");
        stringsFromInput.addElement(args[i]);
      }
    }
    for(int i = 0; i < intsFromInput.size(); i++)
    {
      System.out.print(intsFromInput.get(i) + " ");
    }
    for(int i = 0; i < stringsFromInput.size(); i++)
    {
      System.out.print(stringsFromInput.get(i) + " ");
    }
    System.out.println();
    Collections.sort(intsFromInput);
    Collections.sort(stringsFromInput);

    for(int i = 0; i < intsFromInput.size(); i++)
    {
      System.out.print(intsFromInput.get(i) + " ");
    }
    for(int i = 0; i < stringsFromInput.size(); i++)
    {
      System.out.print(stringsFromInput.get(i) + " ");
    }
    System.out.println();
    StringBuilder jumbleSortedString = new StringBuilder();
    int intCounter = 0;
    int stringCounter = 0;
    for(int i = 0; i < datatypeAtIndex.length; i++)
    {
      System.out.println(jumbleSortedString);
      if(datatypeAtIndex[i])
      {
        jumbleSortedString.append(intsFromInput.get(intCounter) + " ");
        intCounter++;
      }
      else
      {
        jumbleSortedString.append(stringsFromInput.get(stringCounter) + " ");
        stringCounter++;
      }
    }
    System.out.println(jumbleSortedString);
    //Dennis -1 3 4 Michael Richard 11 William Zara 12

  }
}
