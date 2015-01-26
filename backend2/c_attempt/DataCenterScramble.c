#include "DataCenterScramble.h"


int main()
{
  //Store the number of data centers (first line of input)
  int num_data_centers;
  fscanf(stdin,"%d ", &num_data_centers);
  //Create variable to store highest encountered dataset
  int max_data_set_id = 0;
  //Create head pointer to keep track of the start of the data centers
  data_center *head;
  data_center *new_data_center;
  char input_string[1000];

  head = NULL;

  for(int i = 1; i <= num_data_centers; i++)
  {
    //Get the next line of dataset ids for the next data center
    fgets(input_string,1000,stdin);
    //populate new_data_center with that line's info
    new_data_center = (data_center *)malloc(sizeof(data_center));
    new_data_center -> data_sets = (char *)malloc(strlen(input_string));
    char *copy_location = strcpy(new_data_center -> data_sets, input_string);
    // new_data_center -> data_sets = copy_location;
    head = new_data_center;
  }
  for(data_center *current = head; current != NULL; current = current -> next)
  {
    print_data_center(head);
  }

  printf("done\n");
}
void print_data_center(data_center* data_center)
{
  printf("%s", data_center -> data_sets);
}


// data_center* populate_new_data_center(char* start_of_input_string, data_center* new_data_center)
// {
//   new_data_center = (data_center *)malloc(sizeof(data_center));
//   new_data_center -> num_data_sets = 0;
//   //Populate data_center data_sets array
//   return new_data_center;//With all fields populated
// }
