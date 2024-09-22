#include <stdio.h>

  void swaping(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
 
 int main(){
   int n1 = 77;
   int n2 = 13;
   
  printf("Before swap: \n");
  printf("n1 = %d n2 = %d \n", n1, n2);
  
  swaping(&n1, &n2);
  
  printf("After swap: \n");
  printf("n1 = %d n2 = %d\n", n1, n2);

  return 0;
}

