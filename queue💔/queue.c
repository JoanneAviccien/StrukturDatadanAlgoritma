#ifndef queue_h
#define queue_h

#include "dict.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  //Tipe data   //Nama var
  data_isi      antrianbank;
  struct node * nextqueue;
} queue;

queue * buatantrian(int fill){
  queue *temp = (queue*)malloc(sizeof(queue));
  if(temp == nil){
    perror("Fail to allocate </3");
    exit(1);
  }
  temp->antrianbank.noantrian =  fill;
  temp->nextqueue = nil;
  return temp;
}

void enqueue(queue **antrian, int enqueue){
  queue * enqueueit = buatantrian(enqueue);
  queue * temp = *antrian;

  if(*antrian == nil){
    *antrian = enqueueit;
    return;
  }

  while(temp->nextqueue != nil){
    temp = temp->nextqueue;
  }

  enqueueit->nextqueue = temp->nextqueue;
  temp->nextqueue = enqueueit;
}

void dequeue(queue **antrian){
  if(*antrian == nil){
    perror("\nAntrian sudah kosong!");
    exit(1);
  }
  printf("Memproses Antrian: %d", (*antrian)->antrianbank.noantrian);
  queue * rm = *antrian;
  *antrian = (*antrian)->nextqueue;
  free(rm); 
}

void showqueue(queue * antrian){
  if(antrian == nil){
    perror("\nAntrian sudah kosong!");
  }

  queue * temp = antrian;
  printf("\nList Antrian:\n");
  int posisi = 1;
  while(temp != nil){
    printf("Antrian ke-%d: %d\n",posisi ,temp->antrianbank.noantrian);
    ++posisi;
    temp = temp->nextqueue;
  }

}

#endif 
