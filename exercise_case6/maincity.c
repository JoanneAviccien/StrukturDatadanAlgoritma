#include "lib-government/sensus.h"
#include "lib-linklist/dblink.h"
#include <stdio.h>
#include <stdlib.h>

void showmenu() {
  printf("\n=== PROGRAM SENSUS KOTA ===\n");
  printf("1. Buat Kota Baru\n");
  printf("2. Tambah Data Sensus\n");
  printf("3. Hapus Kota\n");
  printf("4. Tampilkan Daftar Kota\n");
  printf("5. Tampilkan Data Sensus\n");
  printf("6. Hapus Semua Data\n");
  printf("0. Keluar\n");
  printf("Pilihan: ");
}

int main() {
  twolink *provinsi = NULL;
  int pilihan;
  char lanjut;

  do {
    system("clear");
    showmenu();
    scanf("%d", &pilihan);
    getchar(); 

    switch (pilihan) {
    case 1:
      buatkota(&provinsi);
      break;
    case 2:
      buatdata(&provinsi);
      break;
    case 3:
      hapuskota(&provinsi);
      break;
    case 4:
      showkota(provinsi);
      break;
    case 5:
      showsensus(provinsi);
      break;
    case 6:
      demolish(&provinsi);
      break;
    case 0:
      exit(0);
    default:
      printf("\nPilihan tidak valid!\n");
    }

    printf("\nTekan Enter untuk melanjutkan...");
    getchar();

  } while (pilihan != 0);

  return 0;
}
