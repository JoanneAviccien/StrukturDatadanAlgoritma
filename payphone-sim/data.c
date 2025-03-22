#ifndef data_h
#define data_h

typedef struct telepon{
  int noantri;
  char *notelp;
  int biaya;
} data;

#include <stdio.h>

void printdata(data print){
  printf("\nNomor Antrian: %d", print.noantri);
  printf("\nNomor yang akan dipanggil: %s", print.notelp);
  printf("\nBiaya Panggilan: Rp.%d", print.biaya);
  printf("\nDurasi Panggilan: %d Menit", print.biaya/500);
}

void setdata(int noantri, char *notelp, int durasi, data * out){
  (*out).noantri = noantri;
  (*out).notelp = notelp;
  (*out).biaya = durasi * 500;
}

#endif
