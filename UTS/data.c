#ifndef data_h
#define data_h

#include "data.h"
#include <stdio.h>
#include <string.h>
typedef struct buku {
  int stok;
  char judul[50];
} buku;

typedef struct orang {
  int prioritas;
  char nama[50];
} orang;

void getstring(char *stream) {
  char temp[50];
  fgets(temp, sizeof(temp), stdin);
  temp[strcspn(temp, "\n")] = 0;
  strcpy(stream, temp);
}

void setbook(char *title, int stock, buku *stream) {
  strcpy(stream->judul, title);
  stream->stok = stock;
}

void bookinfo(buku stream) {
  printf("\n=============================");
  printf("\nJudul buku: %s", stream.judul);
  printf("\nStok buku: %d", stream.stok);
  printf("\n=============================");
}

void infoorang(orang stream) {
  printf("\n=============================");
  printf("\nNama orang: %s", stream.nama);
  printf("\nSkala prioritas: %d", stream.prioritas);
  printf("\n=============================");
}
#endif /* ifndef data_h */
