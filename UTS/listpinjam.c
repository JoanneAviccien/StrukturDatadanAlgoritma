#ifndef special_h
#define special_h

#include "data.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  buku isi;
  struct node *chain;
} speciallist;

bool sisempty(speciallist *list) {
  if (list != NULL) {
    return 0;
  } else {
    return 1;
  }
}

speciallist *screatenode(buku in) {
  // Allocation
  speciallist *newnode = (speciallist *)malloc(sizeof(speciallist));
  if (sisempty(newnode) == 1) {
    perror("\nAlokasi Memori Gagal </3");
    exit(1);
  }
  // Assignment
  newnode->isi = in;
  newnode->chain = NULL;
  return newnode;
}

void sinfront(speciallist **list, buku in) {
  speciallist *newnode = screatenode(in);
  speciallist *yourlist = *list;

  if (sisempty(yourlist) == 1) {
    *list = newnode;
    return;
  }

  newnode->chain = yourlist->chain;
  yourlist->chain = newnode;
}

void sinrear(speciallist **list, buku in) {
  // Assignment
  speciallist *newnode = screatenode(in);
  linkedlist *yourlist = *list;

  if (isempty(yourlist) == 1) {
    *list = newnode;
    return;
  }

  while (yourlist->chain != NULL) {
    yourlist = yourlist->chain;
  }

  newnode->chain = yourlist->chain;
  yourlist->chain = newnode;
}

void sinbetween(linkedlist **list, buku in, int pos) {
  linkedlist *newnode = screatenode(in);
  linkedlist *yourlist = *list;

  if (sisempty(yourlist) == 1) {
    perror("\nList tidak boleh kosong!");
    exit(1);
  }

  if (pos == 1) {
    newnode->chain = *list;
    return;
  } else {
    --pos;
    while (pos != 1) {
      yourlist = yourlist->chain;
      --pos;
    }

    newnode->chain = yourlist->chain;
    yourlist->chain = newnode;
  }
};

void srmfront(linkedlist **list) {

  if (sisempty(*list) == 1) {
    perror("\nTidak ada yang dapat dihapus!");
  }
  printf("Menghapus..");
  linkedlist *temp = *list;
  *list = (*list)->chain;
  free(temp);
}

void srmrear(linkedlist **list) {
  linkedlist *prevend = *list;
  if (sisempty(*list) == 1) {
    perror("\nTidak ada yang dapat dihapus!");
  }

  if (prevend->chain == NULL) {
    free(*list);
    return;
  }

  while (prevend->chain->chain != NULL) {
    prevend = prevend->chain;
  }

  free(prevend->chain);
  prevend->chain = NULL;
}

void srmbetween(linkedlist **list, int pos) {
  linkedlist *prev = NULL;
  linkedlist *rm = *list;

  if (sisempty(rm) == 1) {
    perror("Tidak ada yang dapat dihapus!");
  } else if (pos == 1) {
    *list = rm->chain;
    free(*list);
  } else {
    --pos;
    while (pos != 1) {
      prev = rm;
      rm = rm->chain;
      --pos;
    }
    if (rm != NULL) {
      prev->chain = rm->chain;
      free(rm);
    } else {
      perror("Node tidak tersedia");
    }
  }
}

void sprintlist(linkedlist *list, void (*printfunc)(buku)) {
  if (sisempty(list) == 1) {
    perror("List tidak dapat di print!");
    return;
  }
  linkedlist *print = list;

  while (print != NULL) {
    printfunc(print->isi);
    print = print->chain;
  }
}

#endif
