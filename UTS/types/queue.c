#ifndef queue_h
#define queue_h

#include "../data.h"
#include "../singlylink.h"

void enqueue(linkedlist **queue, buku in) { inrear(queue, in); }

void dequeue(linkedlist **queue) { rmfront(queue); }

#endif
