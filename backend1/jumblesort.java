import java.util.*;

public class jumblesort
{
  public static void main(String[] args)
  {
    /*
    These arrays will hold
    list of strings from stdin
    list of ints from stdin
    the datatype originally at each index of the inputed array
    */
    String[] stringsFromInput = new String[args.length];
    int[] intsFromInput = new int[args.length];
    boolean[] datatypeAtIndex = new boolean[args.length];

    /*
    Now we run through the original list, processing each string or int into
    its respective array and storing the data type at that index in the third
    array
    */
    for(int i = 0; i < args.length; i++)
    {
      int value;
      try{
        //Rudimentary check if value is an integer
        value = Integer.parseInt(args[i]);
        //If no exception thrown, it was and we can add it to the int list
        //Also flip bit in datatype array to signal this index was an int
        System.out.println("Int, adding to int array.");
        intsFromInput[i] = value;
        datatypeAtIndex[i] = true;
      }
      catch(java.lang.NumberFormatException ex)
      {
        System.out.println("Not an int, adding to string array.");
        stringsFromInput[i] = args[i];
      }
    }
    for(int i = 0; i < intsFromInput.length; i++)
    {
      System.out.print(intsFromInput[i] + " ");
    }
    for(int i = 0; i < stringsFromInput.length; i++)
    {
      System.out.print(stringsFromInput[i] + " ");
    }
    System.out.println();

    Arrays.sort(intsFromInput);
    Arrays.sort(stringsFromInput);
    // for(int i = 0; i < intsFromInput.length; i++)
    // {
    //   System.out.print(intsFromInput[i] + " ");
    // }
    // for(int i = 0; i < stringsFromInput.length; i++)
    // {
    //   System.out.print(stringsFromInput[i] + " ");
    // }
    // for(int i = 0; i < args.length; i++)
    // {
    //   if(datatypeAtIndex[i])
    //   {
    //     System.out.println("Value was an integer");
    //   }
    //   else
    //   {
    //     System.out.println("Value was a string");
    //   }
    // }

  }
}
