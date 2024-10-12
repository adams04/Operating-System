#include <stdio.h>

int main(){
  int arr[5] = {10, 32, 45, 67, 89};
  int *ptr = arr;
  printf("Printing the values of the array: \n");
  for(int i = 0; i < 5; i++){
    printf("arr[%d] = %d (via pointer: %d) \n", i, arr[i], *(ptr+i));
  }
  for(int i = 0; i < 5; i++){
    *(ptr + i) += 51;
  }
  printf("Modified array values: \n");
  for(int i = 0; i < 5; i++){
    printf("arr[%d] = %d (via pointer: %d) \n", i, arr[i], *(ptr + i));
  }
  return 0;
 }
