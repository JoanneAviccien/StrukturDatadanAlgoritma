#ifndef linklist_h
#define linklist_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  char namawarga[50];
  struct node * chain;
} linkedlist;

// Validator
bool isempty(linkedlist * list);

// Constructor
linkedlist * createnode(char * in);

// Insert
void inrear(linkedlist ** list, char * in);

// Remove
void rmrear(linkedlist ** list);

#endif // !linklist_h
