#ifndef linklist_h
#define linklist_h

#include "data.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  buku isi;
  struct node *chain;
} linkedlist;

// Validator
bool isempty(linkedlist *list);

// Constructor
linkedlist *createnode(buku in);

// Insert
void infront(linkedlist **list, buku in);
void inrear(linkedlist **list, buku in);
void inbetween(linkedlist **list, buku in, int pos);

// Remove
void rmfront(linkedlist **list);
void rmrear(linkedlist **list);
void rmbetween(linkedlist **list, int pos);

// Display
void printlist(linkedlist *list, void (*printfunc)(buku));

#endif // !linklist_h
