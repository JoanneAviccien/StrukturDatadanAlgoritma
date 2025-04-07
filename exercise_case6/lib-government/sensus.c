#ifndef sensus_h
#define sensus_h

#include "../lib-linklist/dblink.h"
#include "../lib-linklist/singlylink.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getstring(char *stream) {
  char temp[50];
  fgets(temp, sizeof(temp), stdin);
  temp[strcspn(temp, "\n")] = 0;
  strcpy(stream, temp);
}

void buatdata(twolink **provinsi) {
  if (*provinsi == NULL) {
    printf("Error: Belum ada kota yang terdaftar!\n");
    return badend();
  }

  char namakota[50];
  printf("Masukkan nama kota tujuan: ");
  getstring(namakota);

  twolink *current = *provinsi;
  while (current != NULL) {
    if (strcmp(current->isi.isi, namakota) == 0) {
      char isisensus[50];
      printf("Masukan nama penduduk untuk kota %s: ", namakota);
      getstring(isisensus);
      
      linkedlist *temp = current->next;
      while (temp != NULL) {
        if (strcmp(temp->namawarga, isisensus) == 0) {
          printf("Error: Nama penduduk %s sudah terdaftar di kota %s!\n", isisensus, namakota);
          return badend();
        }
        temp = temp->chain;
      }

      inrear(&(current->next), isisensus);
      printf("Data penduduk %s berhasil ditambahkan ke kota %s!\n", isisensus, namakota);
      return end();
    }
    current = current->prev;
  }
  
  printf("Error: Kota %s tidak ditemukan!\n", namakota);
  return badend();
}

void buatkota(twolink **provinsi) {
  data kotabaru;
  char namakota[50];
  getstring(namakota);
  setdata(namakota, &kotabaru);
  dinrear(provinsi, kotabaru);
}

void hapuskota(twolink **provinsi) {
  drmrear(provinsi);
}

void printdata(data stream) { 
  printf("%s", stream.isi);
}

void demolish(twolink **provinsi) {
  if ((*provinsi)->prev == NULL) {
    while ((*provinsi)->next != NULL){
      rmrear((&(*provinsi)->next));
    }
    drmrear(provinsi);
  }
  while ((*provinsi)->prev != NULL) {
    while ((*provinsi)->next != NULL){
      rmrear((&(*provinsi)->next));
    }
    drmrear(provinsi);
  } 
}

void showkota(twolink *provinsi) {
  twolink * temp = provinsi;
  while (temp != NULL){
    printf("\n%s", temp->isi.isi);
    temp = temp->prev;
  }
}

void showsensus(twolink *provinsi) {
  if (provinsi == NULL) {
    printf("\nBelum ada kota yang terdaftar!");
    return;
  }

  char namakota[50];
  printf("\nMasukkan nama kota: ");
  getstring(namakota);

  twolink *current = provinsi;
  while (current != NULL) {
    if (strcmp(current->isi.isi, namakota) == 0) {
      printf("\nData Kota: %s", current->isi.isi);
      printf("\nDaftar Penduduk:");
      
      linkedlist *penduduk = current->next;
      int nomor = 1;
      
      if (penduduk == NULL) {
        printf("\nBelum ada data penduduk.");
      } else {
        while (penduduk != NULL) {
          printf("\n%d. %s", nomor++, penduduk->namawarga);
          penduduk = penduduk->chain;
        }
      }
      printf("\n");
      return;
    }
    current = current->prev;
  }
  printf("\nKota %s tidak ditemukan!\n", namakota);
}

#endif
