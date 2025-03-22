#ifndef linklist_h
#define linklist_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../data.h"

typedef struct node {
  data isi;
  struct node * chain;
} linkedlist;

// Validator
bool isempty(linkedlist * list);

// Constructor
linkedlist * createnode(data in);

// Insert
void infront(linkedlist ** list, data in);
void inrear(linkedlist ** list, data in);
void inbetween(linkedlist ** list, data in, int pos);

// Remove
void rmfront(linkedlist ** list);
void rmrear(linkedlist ** list);
void rmbetween(linkedlist ** list, int pos);

// Display
void printlist(linkedlist * list);
void peeklist(linkedlist * list, int pos);

#endif // !linklist_h
