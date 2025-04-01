#ifndef menu_h
#define menu_h

#include "queue.h"

void newantrian(queue ** antriankita, int noantrian){
  enqueue(antriankita, noantrian);
  showqueue(*antriankita);
}

void rmantrian(queue ** antriankita, int noantrian){
  dequeue(antriankita);
  showqueue(*antriankita);
}

void cetakantrian(queue * antriankita){
  showqueue(antriankita);
}

#endif
