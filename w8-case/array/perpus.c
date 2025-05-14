#ifndef perpus_h
#define perpus_h

#include "perpus.h"
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

booknode *setbook(int setstok, char *setjudul) {
  if (setstok < 0 || setjudul == NULL) {
    printf("Error: Parameter tidak valid\n");
    return NULL;
  }

  booknode *buku = (booknode *)malloc(sizeof(booknode));
  if (buku == NULL) {
    printf("Error: Gagal alokasi memori\n");
    return NULL;
  }

  buku->stok = setstok;
  strncpy(buku->judul, setjudul, sizeof(buku->judul) - 1);
  buku->judul[sizeof(buku->judul) - 1] = '\0';
  buku->first = NULL;
  return buku;
}

reader *newreader(int setprioritas, char *setnama) {
  if (setnama == NULL) {
    printf("Error: Nama tidak valid\n");
    return NULL;
  }

  reader *antrianbaru = (reader *)malloc(sizeof(reader));
  if (antrianbaru == NULL) {
    printf("Error: Gagal alokasi memori\n");
    return NULL;
  }

  antrianbaru->prioritas = setprioritas;
  strncpy(antrianbaru->nama, setnama, sizeof(antrianbaru->nama) - 1);
  antrianbaru->nama[sizeof(antrianbaru->nama) - 1] = '\0';
  antrianbaru->next = NULL;
  return antrianbaru;
}

void enquesort(booknode **buku, char *innama, int inprioritas) {
  if (buku == NULL || *buku == NULL || innama == NULL) {
    printf("Error: Parameter tidak valid\n");
    return;
  }

  reader *orang = newreader(inprioritas, innama);
  if (orang == NULL) {
    return;
  }

  reader *antrian = (*buku)->first;
  reader *prev = NULL;

  if (antrian == NULL) {
    (*buku)->first = orang;
    return;
  }

  if (inprioritas < antrian->prioritas) {
    orang->next = antrian;
    (*buku)->first = orang;
    return;
  }

  while (antrian != NULL && antrian->prioritas <= inprioritas) {
    prev = antrian;
    antrian = antrian->next;
  }

  prev->next = orang;
  orang->next = antrian;
}

void cancelreq(booknode **book, char *nama) {
  reader *todel = (*book)->first;
  
  if (todel == NULL) {
    printf("Error: Antrian Kosong!\n");
    return;
  }
  
  if (strcmp(todel->nama, nama) == 0) {
    (*book)->first = todel->next;
    free(todel);
    printf("Berhasil menghapus %s dari antrian\n", nama);
    return;
  }
  
  reader *prev = todel;
  todel = todel->next;
  
  while (todel != NULL) {
    if (strcmp(todel->nama, nama) == 0) {
      prev->next = todel->next;
      free(todel);
      printf("Berhasil menghapus %s dari antrian\n", nama);
      return;
    }
    prev = todel;
    todel = todel->next;
  }
  
  printf("Error: Peminjam '%s' tidak ditemukan dalam antrian!\n", nama);
}

void deque(booknode **book) {
  if (book == NULL || *book == NULL) {
    printf("Error: Buku tidak valid\n");
    return;
  }

  if ((*book)->first == NULL) {
    printf("Antrian Kosong!\n");
    return;
  }

  reader *rm = (*book)->first;
  (*book)->first = (*book)->first->next;
  free(rm);
  printf("Antrian berhasil diproses\n");
}

void addpeminjam(patron **list, char nama[50], char judul[50]) {
  patron *peminjam = (patron *)malloc(sizeof(patron));
  patron *ptr = *list;
  if (peminjam == NULL) {
    printf("Error: Gagal alokasi memori!\n");
    return;
  }
  strncpy(peminjam->nama, nama, sizeof(peminjam->nama) - 1);
  peminjam->nama[sizeof(peminjam->nama) - 1] = '\0';
  strncpy(peminjam->buku, judul, sizeof(peminjam->buku) - 1);
  peminjam->buku[sizeof(peminjam->buku) - 1] = '\0';
  peminjam->next = NULL;

  if (ptr == NULL) {
    *list = peminjam;
  } else {
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = peminjam;
  }
}

void proses(booknode **book, patron **listpeminjam) {
  if ((*book)->first == NULL) {
    perror("Antrian Kosong!\n");
    return;
  }

  if ((*book)->stok <= 0) {
    perror("Stok buku habis!\n");
    return;
  }

  reader *peminjam = (*book)->first;
  (*book)->stok--;

  addpeminjam(listpeminjam, peminjam->nama, (*book)->judul);

  printf("Buku berhasil dipinjam oleh %s\n", peminjam->nama);
  deque(book);

}

void pengembalian(patron **listpeminjam, booknode **lemari, int pos) {
  if (listpeminjam == NULL || *listpeminjam == NULL) {
    printf("Error: Tidak ada peminjam!\n");
    return;
  }
  
  if (lemari == NULL) {
    printf("Error: Lemari tidak valid!\n");
    return;
  }
  
  if (pos <= 0) {
    printf("Error: Posisi tidak valid!\n");
    return;
  }
  
  int i = 0;
  int rep = 1;
  patron *pengembali = *listpeminjam;
  patron *prev = NULL;
  
  // Mencari peminjam berdasarkan posisi
  while (pengembali != NULL && rep < pos) {
    prev = pengembali;
    pengembali = pengembali->next;
    ++rep;
  }

  if (pengembali == NULL) {
    printf("Error: Posisi peminjam tidak ditemukan!\n");
    return;
  }
  
  // Cari buku yang sesuai di lemari
  i = 0;
  booknode *lemaritujuan = NULL;
  int found = 0;
  
  while (lemari[i] != NULL) {
    if (strcmp(pengembali->buku, lemari[i]->judul) == 0) {
      lemaritujuan = lemari[i];
      found = 1;
      break;
    }
    ++i;
  }
  
  if (!found || lemaritujuan == NULL) {
    perror("Error: Buku tidak ditemukan di lemari!\n");
    return;
  }
  
  ++lemaritujuan->stok;
  printf("Buku %s berhasil dikembalikan oleh %s\n", pengembali->buku, pengembali->nama);
  
  if (prev == NULL) {
    *listpeminjam = pengembali->next;
  } else {
    prev->next = pengembali->next;
  }
  
  free(pengembali);
}

void printqueue(booknode *book) {
  if (book == NULL) {
    printf("Error: Buku tidak valid\n");
    return;
  }

  if (book->first == NULL) {
    printf("Antrian Kosong!\n");
    return;
  }

  printf("\nDaftar Antrian:\n");
  reader *print = book->first;
  int count = 1;
  while (print != NULL) {
    printf("%d. %s (Prioritas: %d)\n", count++, print->nama, print->prioritas);
    print = print->next;
  }
  printf("\n");
}

void printpatron(patron *listpeminjam) {
  patron * ptr = listpeminjam;
  if (listpeminjam != NULL) {
    while (ptr != NULL) {
      printf("\nInfo Peminjam:\n");
      printf("Nama: %s\n", listpeminjam->nama);
      printf("Buku: %s\n", listpeminjam->buku);
      ptr = ptr->next;
    }
  } else {
    perror("tidak ada apapun!");
  }
}
#endif
