#ifndef linklist_h
#define linklist_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
  char namawarga[50];
  struct node * chain;
} linkedlist;

bool isempty(linkedlist * list){
  if(list != NULL){
    return 0;
  }
  else{
    return 1;
  }
}

linkedlist * createnode(char * in){
  // Allocation
  linkedlist * newnode = (linkedlist *)malloc(sizeof(linkedlist));
  if (isempty(newnode) == 1){
    perror("\nAlokasi Memori Gagal </3");
    exit(1);
  }
  // Assignment
  strcpy(newnode->namawarga, in);
  newnode->chain = NULL;
  return newnode;
}

void inrear(linkedlist ** list, char * in){
  //Assignment
  linkedlist * newnode = createnode(in);
  linkedlist * yourlist = *list;

  if(isempty(yourlist) == 1){
    *list = newnode;
    return;
  }

  while(yourlist->chain != NULL){
    yourlist = yourlist->chain;
  }

  newnode->chain = yourlist->chain;
  yourlist->chain = newnode;
}

void rmrear(linkedlist ** list){
  linkedlist * prevend = *list;
  if(isempty(*list) == 1){
    perror("\nTidak ada yang dapat dihapus!");
  }

  if(prevend->chain == NULL){
    free(*list);
    return;
  }

  while(prevend->chain->chain != NULL){
    prevend = prevend->chain;
  }

  free(prevend->chain);
  prevend->chain = NULL;
}

#endif 
