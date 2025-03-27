#include "lib-linklist/linkedlist.h"
#include "lib-government/sensus.h"
#include <stdio.h>

int main(){
  linkedlist * provinsi[5];
  provinsi[0] = NULL;
  provinsi[1] = NULL;
  provinsi[2] = NULL;
  provinsi[3] = NULL;
  provinsi[4] = NULL;
  menu:
    printf("\n===========\nSimcity\n==========");
    int pilihan = 0;
    int kota = 0;
    printf("\n1.Buat Kota baru\n2.Buat Penduduk baru\n3.Tunjukan data sensus\n4.Hapus kota\n5.Keluar simulasi");
    printf("\nMasukan pilihan anda: ");
    scanf("%d", &pilihan);
    getchar();
    if (pilihan == 1) {
      showkota(provinsi);
      printf("\nMasukan kota yang akan diolah: ");
      scanf("%d", &kota);
      getchar();

      buatkota(&provinsi[kota]);
      goto menu;
    }
    if (pilihan == 2) {
      showkota(provinsi);
      printf("\nMasukan kota yang akan diolah: ");
      scanf("%d", &kota);
      getchar();

      buatdata(&provinsi[kota]);
      goto menu;
    }
    if (pilihan == 3){
      showkota(provinsi);
      printf("\nMasukan kota yang akan diolah: ");
      scanf("%d", &kota);
      getchar();

      showsensus(provinsi[kota]);
      goto menu;
    }
    if (pilihan == 4){
      showkota(provinsi);
      printf("\nMasukan kota yang akan diolah: ");
      scanf("%d", &kota);
      getchar();

      hapusdata(&provinsi[kota]);
      goto menu;
    }
    if (pilihan == 5){
      demolish(provinsi);
      exit(0);
    }
    else{
      perror("\nPilihan tidak valid");
      exit(1);
    }    
  return 0;
}
