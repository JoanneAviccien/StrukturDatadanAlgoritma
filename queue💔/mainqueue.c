#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "queue.h"

int main(){
  queue * antrianbank = NULL;
  int noantri = 1;
  int choice = 0;
  void (*menu[2])(queue **, int) = {newantrian, rmantrian};
  again:
    printf("Masukan angka sesuai pilihan anda:\n1.Mengantri\n2.Memproses Antrian\n3.Cetak Antrian\n4.Keluar\nInput anda: ");
    scanf("%d",&choice);
    if (choice == 1 || choice == 2){
      menu[choice - 1](&antrianbank, noantri);
      ++noantri;
      goto again;
    }
    else if (choice == 3) {cetakantrian(antrianbank); goto again;}
    else if (choice == 4) {exit(1);}
    else {
      perror("OPSI TIDAK ADA, HARAP BACA DENGAN BAIK!");
      exit(1);
    } 
  return 0;
}
