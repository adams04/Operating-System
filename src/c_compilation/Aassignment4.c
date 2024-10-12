#include <stdio.h>

int main(){
  int n = 13;
  int *ptr = &n;
  int **dblPtr = &ptr;
  
  printf("Value of the number: %d\n", n);
  printf("Value using pointer: %d\n", *ptr);
  printf("Value using double pointer: %d\n", **dblPtr);
  
  return 0;

}
