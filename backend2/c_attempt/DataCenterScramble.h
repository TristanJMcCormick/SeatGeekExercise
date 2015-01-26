#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct data_center {
  // int num_data_sets;
  // int data_sets[999999];
  char *data_sets;
  struct data_center *next;
}typedef data_center;


void print_data_center(data_center* data_center);
data_center* populate_new_data_center(char* start_of_input_string, data_center* new_data_center);
