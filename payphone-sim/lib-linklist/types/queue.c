#ifndef queue_h
#define queue_h

#include "../linkedlist.h"
#include "../../data.h"

void enqueue(linkedlist ** queue, data in){
  inrear(queue, in);
}

void dequeue(linkedlist ** queue, data in){
  rmfront(queue);
}

#endif
