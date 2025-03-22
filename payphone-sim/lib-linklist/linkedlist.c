#ifndef linklist_h
#define linklist_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../data.h"

typedef struct node {
  data isi;
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

linkedlist * createnode(data in){
  // Allocation
  linkedlist * newnode = (linkedlist *)malloc(sizeof(linkedlist));
  if (isempty(newnode) == 1){
    perror("\nAlokasi Memori Gagal </3");
    exit(1);
  }
  // Assignment
  newnode->isi = in;
  newnode->chain = NULL;
  return newnode;
}

void infront(linkedlist ** list, data in){
  linkedlist * newnode = createnode(in);
  linkedlist * yourlist = *list;
  
  if(isempty(yourlist) == 1){
    *list = newnode;
    return;
  }

  newnode->chain = yourlist->chain;
  yourlist->chain = newnode;
}

void inrear(linkedlist ** list, data in){
  //Assigment
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

void inbetween(linkedlist ** list, data in, int pos){
  linkedlist *newnode = createnode(in);
  linkedlist *yourlist = *list;

  if(isempty(yourlist) == 1){
    perror("\nList tidak boleh kosong!");
    exit(1);
  }

  if(pos == 1){
    newnode->chain = *list ;
    return;
  }
  else{
    --pos;
    while(pos != 1){
     yourlist = yourlist->chain;
     --pos;
    }

    newnode->chain = yourlist->chain;
    yourlist->chain = newnode;
  }
};

void rmfront(linkedlist ** list){

  if(isempty(*list) == 1){
    perror("\nTidak ada yang dapat dihapus!");
  }
  printf("Menghapus..");
  linkedlist * temp = *list;
  *list = (*list)->chain;
  free(temp);
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

void rmbetween(linkedlist ** list, int pos){
  linkedlist * prev = NULL;
  linkedlist * rm = *list;

  if(isempty(rm) == 1){
    perror("Tidak ada yang dapat dihapus (Ts pmo </3)");
  }
  else if(pos == 1){
    *list = rm->chain;
    free(*list);
  }
  else{
    --pos;
    while (pos != 1){
      prev = rm;
      rm = rm->chain;
      --pos;
    }
    if(rm != NULL){
      prev->chain = rm->chain;
      free(rm);
    }
    else{
      perror("Node tidak tersedia");
    }
  }
}

void printlist(linkedlist * list){
  if(isempty(list) == 1){
    perror("List tidak dapat di print (Ts pmo </3)");
  }
  linkedlist * print = list;
  
  while(print != NULL){
    printdata(print->isi);
    print = print->chain;
  }
}

void peeklist(linkedlist * list, int pos){
  if(isempty(list) == 1){
    perror("List tidak dapat di print (Ts pmo </3)");
  }
  linkedlist * print = list;

  --pos;
  while(pos != 1){
    print = print->chain;
    --pos;
  }
  printdata(print->isi);
}

#endif 
