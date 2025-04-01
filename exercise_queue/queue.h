#ifndef queue_h
#define queue_h

#include "dict.h"
#include <stdlib.h>

typedef struct node{
  //Tipe data   //Nama var
  data_isi      antrianbank;
  struct node * nextqueue;
} queue;

queue * buatantrian(int fill);
void enqueue(queue **antrian, int enqueue);
void dequeue(queue **antrian);
void showqueue(queue * antrian);

#endif // !queue_h
