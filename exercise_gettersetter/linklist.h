#ifndef linklist_h
#define linklist_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining New Data Type
typedef struct node {
  int nilai;
  char *nama;
  struct node *link;
} mhsnode;

// Linked List Operation
void createnode(mhsnode *head, int innilai, char *innama);
void insertsortnamemhs(struct node **head, char *innama, int innilai);
bool isempty(struct node * head);
void listcpy(struct node *in, struct node **out);
void removedupe(struct node** head);
void killlist(struct node** head);

#endif // !linklist_h
