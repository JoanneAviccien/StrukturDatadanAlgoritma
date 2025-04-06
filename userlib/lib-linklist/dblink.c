#ifndef dblink_h
#define dblink_h

#include "dblink.h"
#include "../type.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
  struct dnode *prev;
  struct dnode *next;
  data isi;
} twolink;

void end() { printf("Operasi Berhasil Dilakukan"); }
void badend() { printf("Operasi Gagal ts pmo"); }

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
    return end();
  }

  newfront->next = yourlist;
  yourlist->prev = newfront;
}

void dinrear(twolink **list, data stream) {
  twolink *newrear = newdnode(stream);
  twolink *yourlist = *list;

  if (isempty(yourlist) == 1) {
    *list = newrear;
    return end();
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
    return badend();
  }

  if (pos == 1) {
    newbetween->next = *list;
    (*list)->prev = newbetween;
    *list = newbetween;
    return end();
  }

  else {
    --pos;
    while (pos != 1) {
      yourlist = yourlist->next;
      --pos;
    }

    newbetween->next = yourlist->next;
    newbetween->prev = yourlist;
    if (yourlist->next != NULL) {
      yourlist->next->prev = newbetween;
    }
    yourlist->next = newbetween;
  }
}

void drmfront(twolink **list) {
  if (isempty(*list) == 1) {
    perror("\nTidak ada yang dapat dihapus!");
    return badend();
  }
  twolink *temp = *list;
  *list = (*list)->next;
  free(temp);
  return end();
}

void drmrear(twolink **list) {
  if (isempty(*list) == 1) {
    perror("\nTidak ada yang dapat dihapus!");
    return badend();
  }
  if ((*list)->next == NULL) {
    free(*list);
    return end();
  }
  twolink *temp = *list;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->prev->next = NULL;
  free(temp);
  return end();
}

void drmbetween(twolink **list, int pos) {
  twolink *removed = *list;
  twolink *connect = NULL;
  if (isempty(*list) == 1) {
    perror("\nTidak ada yang dapat dihapus!");
    return badend();
  }
  if (pos == 1) {
    drmfront(list);
    return end();
  } else {
    --pos;
    while (pos != 1 && removed->next != NULL) {
      removed = removed->next;
      --pos;
    }
    if (removed->next != NULL) {
      connect = removed->prev;
      connect->next = removed->next;
      removed->next->prev = connect;
      return end();
    } else {
      return badend();
    }
  }
}

void travel(twolink *list, char gear, void (*func)(data)) {
  twolink *yourlist = list;
  switch (gear) {
  case 'd':
    func(yourlist->isi);
    travel(yourlist->next, gear, func);
    break;
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

void dlistcpy(twolink *source, twolink **stream) {}

#endif
