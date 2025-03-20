#include "binaryops.h"
#include "stack.h"
#include <stdio.h>

int main(){
  stack *converted = NULL;
  convertdec(&converted);
  printf("Sebelum pop/Sesudah push: \n");
  peek(converted);
  printf("\n");
  while(converted != NULL){
    pop(&converted);
  }
  printf("\n");
  printf("Setelah melakukan operasi pop: \n");
  peek(converted);

  return 0;
}
