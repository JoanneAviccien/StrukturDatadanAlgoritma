#include "data.h"
#include "menu.h"
#include "singlylink.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  linkedlist *lemaribuku = NULL;

  int pilihan = 0;
menu:
  printf("\n1. Tambahkan buku\n2. Cek isi lemaribuku");
  printf("\nMasukan opsi anda:");
  scanf("%d", &pilihan);
  getchar();
  switch (pilihan) {
  case 1:
    addbook(&lemaribuku);
    break;
  case 2:
    printf("\nLemari Buku Perpustakaan");
    printlist(lemaribuku, bookinfo);
    break;
  default:
    perror("\nOpsi tidak ada!");
  }
  printf("\nTekan enter untuk lanjut.....");
  getchar();
  system("clear");
  goto menu;

  return 0;
}
