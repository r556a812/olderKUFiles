#include <stdlib.h>
#include <stdio.h>
#include "libpriqueue.h"

int compare1(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}


int main (int argc, char *argv[])
{
  priqueue_t q;

  priqueue_init(&q, compare1);

  long int values[5] = {1, 2, 3, 4, 5};
  for(int i = 0; i < 5; i++)
  {
    priqueue_offer(&q, (void *)values[i]);
    printf("%d ", values[i]);
    printf("%d ", priqueue_peek(&q));
  }
  
  return 0;

}
