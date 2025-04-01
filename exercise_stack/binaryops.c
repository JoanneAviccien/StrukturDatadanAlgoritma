#ifndef binaryops_h
#define binaryops_h

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int getdecnum(){
  int decimal = 0;
  printf("Masukan Angka Decimal: \n");
  scanf("%d", &decimal);
  return decimal;
}

void convertdec(stack **storage){
  int num = getdecnum();
  if (num < 0){
    perror("nuh uh");
    exit(1);
  }
  else {
    while (num !=0){
      push(storage, num % 2);
      peek(*storage);
      printf("\n");
      num = num / 2;
    }
  }
}

#endif 
