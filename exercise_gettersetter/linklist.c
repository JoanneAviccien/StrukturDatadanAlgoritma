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

bool isempty(struct node * head){
  return (head == NULL);
}

void listcpy(struct node *in, struct node** out){
  while (in != NULL){
    if (in->nilai > 70){
      insertsortnamemhs(out, in->nama, in->nilai);
    }
    in = in->link;
  }
}

void removedupe(struct node** head) {
  if (isempty(*head)){
    perror("List kosong!");
  };

  struct node * cur = *head;
    
  while (cur != NULL) {
    struct node * prev = cur;
    struct node * temp = cur->link;  
    while (temp != NULL) {
      if (strcmp(temp->nama, cur->nama) == 0) {
        prev->link = temp->link;
        free(temp->nama);
        free(temp);
        temp = prev->link;
      }
      else {
        prev = temp;
        temp = temp->link;
      }
    }
    cur = cur->link;
  }
}

void killlist(struct node **head){

	if(isempty(*head)){
		perror("List sudah kosong!\n");
		return;
	}

	struct node * temp = *head;

	while(*head != NULL){
	
		temp = *head;
		*head = (*head)->link;
		free(temp->nama);
		free(temp);
	}

}

#endif
