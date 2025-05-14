#ifndef perpus_h
#define perpus_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pembaca {
  int prioritas;
  char nama[50];
  struct pembaca *next;
} reader;

typedef struct lemari {
  char judul[50];
  int stok;
  struct pembaca *first;
} booknode;

typedef struct peminjam {
  char nama[50];
  char buku[50];
  struct peminjam *next;
} patron;

booknode *setbook(int setstok, char *setjudul);
reader *newreader(int setprioritas, char *setnama);

void printqueue(booknode *book);
void printpatron(patron *listpeminjam);

void deque(booknode **book);
void enquesort(booknode **buku, char *innama, int prioritas);
void addpeminjam(patron **listpeminjam, char *innama, char *inbuku);
void proses(booknode **book, patron **listpeminjam);
void pengembalian(patron **listpeminjam, booknode **lemari, int pos);
void cancelreq(booknode **book, char *nama);

#endif
