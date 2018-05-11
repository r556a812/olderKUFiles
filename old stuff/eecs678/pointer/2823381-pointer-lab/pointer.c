#include <stdio.h>    
#include <stdlib.h>                                            
#include <string.h>
#include <unistd.h>

//*Arrays to hold the values for the pid, arrival 
//time, and priority in respective order*/
int arr_time_array[7] = {10, 4, 14, 6, 2, 8, 12};
int priority_array[7] = {3, 0, 0, 1, 1, 2, 3};
int arr_pid_array[2][7] = {{10, 4, 14, 6, 2, 8, 12}, {5, 2, 7, 3, 1, 4, 6}};
int priority_pid_array[2][7] = {{3, 0, 0, 1, 1, 2, 3}, {5, 2, 7, 3, 1, 4, 6}};

//*Function for sorting ascending order*/
int ascending_order(const void *a, const void *b)
{
    int one = *(const int *)a;
    int two = *(const int *)b;
    return (one - two);
}

//*Function for sorting descending oreder*/
int descending_order(const void *a, const void *b)
{
    int one = *(const int *)a;
    int two = *(const int *)b;
    return (two - one);
}



int main(int argc, char* argv[])
{
  int nmemb = 7;
  int * comparer;
  
  qsort((void*)priority_array, nmemb, sizeof(priority_array[0]), descending_order);
  
  printf("Order by Priority in descending order: ");
  
  for (int i = 0; i < 7; i++)
  {
    int place1 = 0;
    
    while(priority_array[i] != priority_pid_array[0][place1])
    {
      place1++;
    }

    if (priority_array[i] == priority_array[i+1])
    {
      int place2 = place1+1;
      while (priority_array[i] != priority_pid_array[0][place2])
      {
        place2++;
      }
     
      int num1 = priority_pid_array[1][place1];
      int num2 = priority_pid_array[1][place2];

      if (arr_pid_array[0][place1] < arr_pid_array[0][place2])
      {
        printf("%d  %d  ", num1, num2);
        i++;
      }
      else
      {
        printf("%d  %d  ", num2, num1);
        i++;
      }
    }
    else
    {
      printf("%d  ", priority_pid_array[1][place1]);
    }
  }
  
  printf("\n\n");

  qsort((void*)arr_time_array, nmemb, sizeof(priority_array[0]), ascending_order);
  
  printf("Order by Arrival Time in ascending order: ");

  for(int j = 0; j < 7; j++)
  {
    int spot = 0;
    while(arr_time_array[j] != arr_pid_array[0][spot])
    {
      spot++;
    }

    printf("%d  ", arr_pid_array[1][spot]);
  }
  
  printf("\n\n");
  
  return 0;
}


