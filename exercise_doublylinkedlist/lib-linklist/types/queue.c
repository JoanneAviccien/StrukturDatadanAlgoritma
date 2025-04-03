#ifndef queue_h
#define queue_h

#include "../singlylink.h"
#include "../../data.h"

void enqueue(linkedlist ** queue, data in){
  inrear(queue, in);
}

void dequeue(linkedlist ** queue){
  rmfront(queue);
}

#endif
