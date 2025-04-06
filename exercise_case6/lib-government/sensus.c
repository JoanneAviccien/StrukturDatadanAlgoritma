#ifndef sensus_h
#define sensus_h

#include "../userlib/lib-linklist/dblink.h"
#include "type.h"
#include <stdio.h>
#include <string.h>

void getstring(char *stream) {
  char temp[50];
  fgets(temp, sizeof(temp), stdin);
  temp[strcspn(temp, "\n")] = 0;
  strcpy(stream, temp);
}

void buatdata(twolink **kota) {
  data databaru;
  char namabaru[50];
  printf("Masukan Isi baru: ");
  getstring(namabaru);
  setdata(namabaru, &databaru);
}

void buatkota(twolink **kota) {
  data databaru;
  char namabaru[50];
  printf("Masukan namakota: ");
  getstring(namabaru);
  setdata(namabaru, &databaru);
}

void hapuskan(twolink **kota) {
  if (*kota == NULL) {
    printf("Kota sudah kosong\n");
    return;
  }
  while (*kota != NULL) {
  }
}

void hapusdata(twolink **kota) {}

void demolish(twolink **provinsi) {}

void showkota(twolink *provinsi) {}

void showsensus(twolink *datasensus) {}

#endif
