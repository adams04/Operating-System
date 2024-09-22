#include <stdio.h>

int main(){
  int number = 77;
  int *ptr = &number;
  printf("The address of number integer: %p\n",&number);
  printf("The address of number integer: %p\n", &ptr);
  
  *ptr = 100;
  printf("New value of num: %d\n",number);
  return 0;
 }
