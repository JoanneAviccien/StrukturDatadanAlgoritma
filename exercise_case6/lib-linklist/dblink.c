#ifndef dblink_h
#define dblink_h

#include "dblink.h"
#include "../lib-government/type.h"
#include "singlylink.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dnode {
  struct dnode *prev;
  struct node *next;
  data isi;
} twolink;

void end() { printf("\nOperasi Berhasil Dilakukan"); }
void badend() { printf("\nOperasi Gagal"); }

bool isemptydb(twolink *list) {
  if (list != NULL) {
    return 0;
  } else {
    return 1;
  }
}

twolink *newdnode(data isinode) {
  twolink *newdnode = (twolink *)malloc(sizeof(twolink));
  if (isemptydb(newdnode) == 1) {
    perror("Tidak bisa alokasi, ts pmo");
    exit(1);
  }
  newdnode->isi = isinode;
  newdnode->next = NULL;
  newdnode->prev = NULL;
  return newdnode;
}

void dinrear(twolink **list, data stream) {
  twolink *newrear = newdnode(stream);
  twolink *yourlist = *list;

  if (isemptydb(yourlist) == 1) {
    *list = newrear;
    return end();
  }

  while (yourlist->prev != NULL) {
    yourlist = yourlist->prev;
  }

  newrear->prev = yourlist->prev;
  yourlist->prev = newrear;
}

void drmrear(twolink **list) {
  if (isemptydb(*list) == 1) {
    perror("\nTidak ada yang dapat dihapus!");
    return badend();
  }
  if ((*list)->prev == NULL) {
    free(*list);
    return end();
  }
  twolink *temp = *list;
  while (temp->prev != NULL) {
    temp = temp->prev;
  }
  free(temp->prev);
  return end();
}

void travel(twolink *list, char gear, void (*func)(data)) {
  if (list == NULL) {
    return badend();
  }
  twolink *yourlist = list;
  switch (gear) {
  case 'r':
    func(yourlist->isi);
    travel(yourlist->prev, gear, func);
    break;
  default:
    perror("\nInvalid traverse type!");
    return badend();
    break;
  }
}

#endif
