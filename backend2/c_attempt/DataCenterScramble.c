#include "DataCenterScramble.h"

int main(int argc, const char * argv[]) {
  //Store the number of data centers (first line of input)
  int num_data_centers;
  fscanf(stdin,"%d ", &num_data_centers);
  //Create variable to store highest encountered dataset
  int max_data_set_id = 0;
  //Create head pointer to keep track of the start of the data centers
  data_center *head;
  data_center *tail;
  head = NULL;

  create_data_center_list(&head, &tail, num_data_centers, &max_data_set_id);

  print_list(head,max_data_set_id);

  copy_data_sets(head, max_data_set_id, num_data_centers);

}

void copy_data_sets(data_center* head, int max_data_set_id, int num_data_centers){
  /*grab first data center, store id
  For every index == 1 in that data center -> data_sets[] and not in already_copied, go to
  all the next data_centers and see if next_data_center -> datasets[i] == 1. If not,
  print "index n target_data_center\n", go to next data_center
  compare its id to the starting id. If equal, you're done, add that index to
  already_copied_id's and grab next index. Check if greater than max_data_set_id
  Once it is, you're done.
  */
  int already_copied_data_sets[max_data_set_id];

  data_center* current_source_data_center = head;
  int first_data_center_id = current_source_data_center -> data_center_id;
  for(int i = 1; i <= 3; i++)
  {
    for(int i = 1; i <= max_data_set_id; i++)
    {
      if(current_source_data_center -> data_sets[i] == 1 && already_copied_data_sets[i] != 1)
      {
        //If we've got the data set in the given data center and it hasn't already been
        //copied, get to copying it forward. Create a pointer to run out along the
        //remaining data centers and check for presence of this data set. Where absent, copy.
        int source_data_center_id = current_source_data_center -> data_center_id;
        data_center* current_destination_data_center = current_source_data_center -> next;
        while(current_destination_data_center -> data_center_id != source_data_center_id)
        {
          if(current_destination_data_center -> data_sets[i] != 1)
          {
            //Destination data center does not have data set. Print copy message!
            printf("%i %i %i\n", i, current_source_data_center -> data_center_id, current_destination_data_center -> data_center_id);
            //mark it as copied at the destination data center
            current_destination_data_center -> data_sets[i] = 1;
          }
          //Check the next data center
          current_destination_data_center = current_destination_data_center -> next;
        }
        //We've come back around to where we first found the dataset. Note that it's
        //been copied, and go to the next one
        already_copied_data_sets[i] = 1;
      }
    }
    current_source_data_center = current_source_data_center -> next;
  }
}

void create_data_center_list(data_center** list_head, data_center **list_tail, int num_data_centers,int* max_data_set_id)
{
  char input_string[1000];
  data_center *new_data_center = (data_center *)malloc(sizeof(data_center));
  *list_tail = new_data_center;//Assigns a tail pointer to keep track of the first data center
  for(int i = 1; i <= num_data_centers; i++)
  {
    //Get the next line of dataset ids for the next data center, up to 1000 characters
    fgets(input_string,1000,stdin);
    //populate new_data_center with that line's info
    new_data_center -> data_center_id = i;
    populate_new_data_center(input_string, new_data_center, max_data_set_id);
    new_data_center -> next = *list_head;
    *list_head = new_data_center;
    new_data_center = (data_center *)malloc(sizeof(data_center));
  }
  (*list_tail) -> next = *list_head;
}

data_center* populate_new_data_center(char* start_of_input_string, data_center* new_data_center, int *max_data_set_id)
{
  //Populate data_center data_sets array
  for(char *counter = &start_of_input_string[0]; *counter != '\n';counter++)
  {
    if(*counter != ' '){
      int current_data_set_id = 0;
      sscanf(counter,"%d",&current_data_set_id);
      new_data_center -> data_sets[current_data_set_id] = 1;
      if(current_data_set_id > *max_data_set_id)
      {
        *max_data_set_id = current_data_set_id;
      }
    }
  }
  return new_data_center;
}
void print_list(data_center *head, int max_data_set_id)
{
  int starting_data_center_id = head -> data_center_id;
  data_center* counter = head;
  do {
    printf("Data Center %i: ",counter -> data_center_id);
    for(int i = 0; i <= max_data_set_id; i++)
    {
      printf("%d",counter -> data_sets[i]);
    }
    counter = counter -> next;
    printf("\n");
  }while(counter -> data_center_id != starting_data_center_id);
}
