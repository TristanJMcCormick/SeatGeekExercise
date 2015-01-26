#import "DataCenterScramble.h"


int main()
{
  char input_string[1000];
  int data_centers;
  fscanf(stdin,"%d ", &data_centers);
  for(int i = 1; i <= data_centers; i++)
  {
    fgets(input_string,1000,stdin);
    printf("%s",input_string);
  }
  printf("done\n");
}
