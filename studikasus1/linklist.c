#ifndef linklist_h
#define linklist_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
  int nilai;
  char *nama;
  struct node *link;
} mhsnode;

struct node * createnode(int innilai, char *innama){
  struct node * temp = (struct node *)malloc(sizeof(mhsnode));
  temp->nama = innama;
  temp->nilai= innilai;
  temp->link = NULL;
  return temp;
};

void insertsortnamemhs(struct node **head, char *innama, int innilai){
  printf("Inserting Node...\n");
  struct node *newnode = createnode(innilai, innama);
  struct node *temp = *head;

  if (*head == NULL || strcmp((*head)->nama, innama) > 0) {
        newnode->link = *head;
        *head = newnode;
        return;
    }

  while (temp->link != NULL && strcmp(temp->link->nama, innama) < 0) {
    temp = temp->link;
  }

  newnode->link = temp->link;
  temp->link= newnode;
}

#endif
