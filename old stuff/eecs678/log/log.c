#include <stdio.h>    
#include <math.h>


int main()
{
  double num3,num4;
  int num1, num2;
  num3 = 256;
  num4 = 257;
  num1 = ceil(log2(num3));
  num2 = ceil(log2(num4));
  
  printf("%d  %d", num1, num2);

 
  return 0;
}


