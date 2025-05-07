#ifndef menu_h
#define menu_h

#include "singlylink.h"

void addbook(linkedlist **lemaribuku) {
  buku newbook;
  char judul[50];
  int stok;
  printf("Masukan judul buku: ");
  getstring(judul);
  printf("Masukan Jumlah Stok buku:");
  scanf("%d", &stok);
  setbook(judul, stok, &newbook);
  infront(lemaribuku, newbook);
}

#endif /* ifndef menu_h */
