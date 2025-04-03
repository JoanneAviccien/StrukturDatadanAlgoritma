#ifndef dblink_h
#define dblink_h

#include "../type.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
  struct dnode *prev;
  struct dnode *next;
  data isi;
} twolink;

bool isempty(twolink *list) {
  if (list != NULL) {
    return 0;
  } else {
    return 1;
  }
}

twolink *newdnode(data isinode) {
  twolink *newdnode = (twolink *)malloc(sizeof(twolink));
  if (isempty(newdnode) == 1) {
    perror("Tidak bisa alokasi, ts pmo");
    exit(1);
  }
  newdnode->isi = isinode;
  newdnode->next = NULL;
  newdnode->prev = NULL;
  return newdnode;
}

void dinfront(twolink **list, data stream) {
  twolink *newfront = newdnode(stream);
  twolink *yourlist = *list;

  if (isempty(yourlist) == 1) {
    *list = newfront;
    return;
  }

  newfront->next = yourlist;
  yourlist->prev = newfront;
}

void dinrear(twolink **list, data stream) {
  twolink *newrear = newdnode(stream);
  twolink *yourlist = *list;

  if (isempty(yourlist) == 1) {
    *list = newrear;
    return;
  }

  while (yourlist->next != NULL) {
    yourlist = yourlist->next;
  }

  yourlist->next = newrear;
  newrear->prev = yourlist;
}

void dinbetween(twolink **list, data stream, int pos) {
  twolink *newbetween = newdnode(stream);
  twolink *yourlist = *list;

  if (isempty(yourlist) == 1) {
    perror("\nList tidak boleh kosong!");
    exit(1);
  }

  if (pos == 1) {
    newbetween->next = *list;
    (*list)->prev = newbetween;
    return;
  }

  else {
    --pos;
    while (pos != 1) {
      yourlist = yourlist->next;
      --pos;
    }
  }
}

void travel(twolink *list, char gear) {
  switch (gear) {
  case 'd':
    break;
  case 'r':
    break;
  default:
    perror("\nInvalid traverse type!");
    exit(1);
    break;
  }
}

void dlistcpy(twolink *source, twolink **stream) {}

#endif
