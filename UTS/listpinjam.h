#ifndef special_h
#define special_h

#include "data.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  buku isi;
  struct node *chain;
} linkedlist;

// Validator
bool sisempty(linkedlist *list);

// Constructor
linkedlist *screatenode(buku in);

// Insert
void sinfront(linkedlist **list, buku in);
void sinrear(linkedlist **list, buku in);
void sinbetween(linkedlist **list, buku in, int pos);

// Remove
void srmfront(linkedlist **list);
void srmrear(linkedlist **list);
void srmbetween(linkedlist **list, int pos);

// Display
void sprintlist(linkedlist *list, void (*printfunc)(buku));

#endif // !linklist_h
