#include "perpus.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  booknode *lemari[2];
  patron *listpeminjam = NULL;
  lemari[0] = NULL;
  lemari[1] = NULL;

  lemari[0] = setbook(1, "buku1");
  if (lemari[0] == NULL) {
    printf("Gagal membuat buku pertama\n");
    return 1;
  }

  lemari[1] = setbook(1, "buku2");
  if (lemari[1] == NULL) {
    printf("Gagal membuat buku kedua\n");
    free(lemari[0]);
    return 1;
  }

  printf("\nDaftar Buku:\n");
  printf("1. %s\n", lemari[0]->judul);
  printf("2. %s\n", lemari[1]->judul);

  printf("\n========= Antrian Buku 1 =========");
  enquesort(&lemari[0], "mhs1", 2);
  printqueue(lemari[0]);

  enquesort(&lemari[0], "dosen1", 1);
  printqueue(lemari[0]);

  enquesort(&lemari[0], "umum1", 3);
  printqueue(lemari[0]);

  printf("\n========= Antrian Buku 2 =========");
  enquesort(&lemari[1], "umum1", 3);
  printqueue(lemari[1]);
  printf("\nSetelah di cancel: ");
  cancelreq(&lemari[1], "umum1");
  printqueue(lemari[1]);

  printf("\nPemrosesan Dosen\n");
  proses(&lemari[0], &listpeminjam);
  printqueue(lemari[0]);
  printf("Pengecekan Pemrosesan MHS\n");
  proses(&lemari[0], &listpeminjam);
  printpatron(listpeminjam);

  printf("\ntest pengembalian..\n");
  pengembalian(&listpeminjam, lemari, 1);
  printf("\nPrint Ulang List peminjam:\n");
  printpatron(listpeminjam);

  free(lemari[0]);
  free(lemari[1]);

  return 0;
}