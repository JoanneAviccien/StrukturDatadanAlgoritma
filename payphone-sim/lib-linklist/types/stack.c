#ifndef stack_h
#define stack_h

#include "../linkedlist.h"
#include "../../data.h"

void push (linkedlist ** stack, data in){
  infront(stack,in);
}

void pop (linkedlist ** stack){
  rmfront(stack);
}

#endif
