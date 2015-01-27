#include "DataCenterScramble.h"

int main(int argc, const char * argv[]) {
  //Store the number of data centers (first line of input)
  int num_data_centers;
  fscanf(stdin,"%d ", &num_data_centers);
  //Create variable to store highest encountered dataset
  int max_data_set_id = 0;
  //Create head pointer to keep track of the start of the data centers
  data_center *head;
  head = NULL;

  create_data_center_list(&head, num_data_centers, &max_data_set_id);

  print_list(head,max_data_set_id);

  copy_data_sets(head, max_data_set_id);

  printf("done");
}

void copy_data_sets(data_center* head, int max_data_set_id){
  /*grab data center n
  For every index == 1 in n -> data_sets[] and not in already_copied, go to
  the next data_center and see if next_data_center -> datasets[i] == 1. If not,
  print "index n target_data_center\n", go to next data_center
  compare its id to the starting id. If equal, you're done, add that index to
  already_copied_id's and grab next index. Check if greater than max_data_set_id
  Once it is, you're done.
  */
  int already_copied_data_sets[max_data_set_id];

  data_center* current_source_data_center = head;
  int current_data_center_id = current_source_data_center -> data_center_id;
  while(current_source_data_center != NULL)
  {
    for(int i = 0; i < max_data_set_id; i++)
    {
      if(current_source_data_center -> data_sets[i] == 1 && already_copied_data_sets[i] != 1)
      {
        //If we've got the data set in the given data center and it hasn't already been
        //copied, get to copying it forward. Create a pointer to run out along the
        //remaining data centers and check for presence of this data set. Where absent, copy.
        data_center* current_destination_data_center = current_source_data_center -> next;
        while(current_destination_data_center != NULL)
        {
          if(current_destination_data_center -> data_sets[i] != 1)
          {
            printf("%i %i %i\n", i, current_source_data_center -> data_center_id, current_destination_data_center -> data_center_id);
            //mark it as copied at the destination data center
            current_destination_data_center -> data_sets[i] = 1;
          }
          current_destination_data_center = current_destination_data_center -> next;
        }
      }
    }
    current_source_data_center = current_source_data_center -> next;
  }
}

void create_data_center_list(data_center** list_head,int num_data_centers,int* max_data_set_id)
{
  char input_string[1000];
  data_center *new_data_center;
  for(int i = 1; i <= num_data_centers; i++)
  {
    //Get the next line of dataset ids for the next data center
    fgets(input_string,10,stdin);
    //populate new_data_center with that line's info
    new_data_center = (data_center *)malloc(sizeof(data_center));
    new_data_center -> num_data_sets = 0;
    new_data_center -> data_center_id = i;
    populate_new_data_center(input_string, new_data_center, max_data_set_id);
    new_data_center -> next = *list_head;
    *list_head = new_data_center;
  }
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
      new_data_center -> num_data_sets++;
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
  for(data_center *counter = head; counter != NULL; counter = counter -> next)
  {
    printf("Data Center %i: ",counter -> data_center_id);
    for(int i = 0; i < max_data_set_id; i++)
    {
      printf("%d",counter -> data_sets[i+1]);
    }
    printf("\n");
  }
}
