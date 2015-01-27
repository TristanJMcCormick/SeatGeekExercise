#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct data_center {
  int data_center_id;
  int data_sets[999999];
  struct data_center *next;
}typedef data_center;


void copy_data_sets(data_center* head, int max_data_set_id, int num_data_centers);
void create_data_center_list(data_center** list_head, data_center **list_tail, int num_data_centers,int* max_data_set_id);
data_center* populate_new_data_center(char* start_of_input_string, data_center* new_data_center, int *max_data_set_id);
void print_list(data_center *head, int max_data_set_id);
