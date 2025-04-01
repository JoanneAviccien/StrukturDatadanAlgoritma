#ifndef display_h
#define display_h

#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linklist.h"

void separator(char *title){
  printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ %s ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n", title);
}

int countmhs(mhsnode *head){
  int count = 0;
  if (head == NULL){
    perror("Nothing at the linked list!");
  }
  else {
    mhsnode *ptr = NULL;
    ptr = head; 
    while (ptr != NULL){
      ++count;
      ptr = ptr->link;
    }
  }
  printf("Jumlah Mahasiswa: %d\n", count);
  return count;
}

void printmhs(mhsnode *head){
  if (head == NULL){
    perror("Nothing at the linked list!");
  }
  mhsnode *ptr = NULL;
  ptr = head;
  while (ptr != NULL){
    printf("Nama mahasiswa: %s\n", ptr->nama);
    printf("Nilai mahasiswa: %d\n", ptr->nilai);
    ptr = ptr->link;
  }
}

void sortgrademhs(struct node * head) {
  int i, j, count = countmhs(head);
    
  if (count == 0) {
      printf("List Kosong!\n\n");
      return;
  }
 
  struct node **arr = (struct node**)malloc(count * sizeof(struct node *));
  struct node *temp = head;
    
  for (i = 0; i < count; ++i) {
    arr[i] = temp;
    temp = temp->link;
  }
 
  for (i = 0; i < count - 1; ++i) {
    for (j = 0; j < count - i - 1; ++j) {
      if (arr[j]->nilai < arr[j + 1]->nilai) {
        struct node * swap = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = swap;
      }
    }
  } 

  for (i = 0; i < count; i++) {
    printf("Nama mahasiswa: %s\n", arr[i]->nama);
    printf("Nilai mahasiswa: %d\n", arr[i]->nilai);
  }
  free(arr);
}



#endif
