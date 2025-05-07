#ifndef data_h
#define data_h

#include <stdio.h>
#include <string.h>

typedef struct buku {
  char judul[50];
  int stok;
} buku;

typedef struct orang {
  int prioritas;
  char nama[50];
} orang;

void getstring(char *stream);

void setbook(char *title, int stock, buku *stream);
void setorang(char *nama, int prioritas, orang *stream);

void bookinfo(buku stream);
void infoorang(orang stream);

#endif // !data_h
