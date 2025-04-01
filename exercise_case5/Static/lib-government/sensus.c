#ifndef sensus_h
#define sensus_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib-linklist/linkedlist.h"
#include "data.h"

void buatdata(linkedlist ** kota){
  data databaru;
  char namabaru[50];
  printf("Masukan Isi baru: ");
  fgets(namabaru, 50, stdin);
  namabaru[strcspn(namabaru, "\n")] = 0;
  setdata(namabaru, &databaru);
  inrear(kota, databaru);
}

void buatkota(linkedlist ** kota){
  data databaru;
  char namabaru[50];
  printf("Masukan namakota: ");
  fgets(namabaru, 50, stdin);
  namabaru[strcspn(namabaru, "\n")] = 0;
  setdata(namabaru, &databaru);
  inrear(kota, databaru);
}

void hapuskan(linkedlist ** kota){
  if(*kota == NULL){
    printf("Kota sudah kosong\n");
    return;
  }
  while(*kota != NULL){
    rmfront(kota); 
  }

}

void hapusdata(linkedlist ** kota){
  char choice;
  printf("Yakin akan menghapus kota? Y/N: ");
  scanf("%c", &choice);
  getchar();
  if(choice == 'y' || choice == 'Y'){
    hapuskan(kota);
  }
  else if(choice == 'n' || choice == 'N'){
    return;
  }
  else{
    return;
  }
}

void demolish(linkedlist * provinsi[5]){
  int i = 0;
  while(i<5){
    if (provinsi[i] != NULL){
      hapuskan(&provinsi[i]);
    }
    ++i;
  }
}

void showkota(linkedlist * provinsi[5]){
  int i = 0;
  while(i < 5){
    if (provinsi[i] != NULL){
      printf("%d. %s\n", i, provinsi[i]->isi.isi);
    }else {
      printf("%d. Lahan Kosong\n", i);
    }
    ++i;
  }
}

void showsensus(linkedlist * datasensus){
  if(isempty(datasensus) == 1){
    perror("List tidak dapat di print (Ts pmo </3)");
    return;
  }
  else{
    linkedlist * print = datasensus;
    printf("Nama Kota: %s\n", print->isi.isi);
    print = print->chain;
  
    while(print != NULL){
      printf("Isi data sensus: %s\n", print->isi.isi);
      print = print->chain;
    }  
  }
}

#endif 
