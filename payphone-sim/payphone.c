#ifndef payphone_h
#define payphone_h

#include "data.h"
#include "lib-linklist/linkedlist.h"
#include "lib-linklist/types/queue.h"
#include "lib-linklist/types/stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isnumvalid(char *notelp){
  if(strlen(notelp) < 13 || strlen(notelp) == 13){
    return 0;
  }else{
    perror("Nomor telepon tidak valid!");
    return 1;
  }
}

void usebooth(int * noantri, linkedlist ** antrian){
  data phonecall;
  char newnum[13];
  int min = 0;
  printf("Nomor telepon yang akan dipanggil: ");
  if (fgets(newnum, 13, stdin) != NULL) {
    newnum[strcspn(newnum, "\n")] = 0;
    printf("Durasi Panggilan: ");
    scanf("%d", &min);
    setdata(*noantri, newnum, min, &phonecall);
    enqueue(antrian, phonecall);
    ++*noantri; 
  }
}

void printkontak(linkedlist * list){
  if(isempty(list) == 1){
    printf("Buku kontak masih kosong!\n");
    return;
  }
  linkedlist * print = list;
  int i = 1;
  
  while(print != NULL){
    printf("%d. %s\n", i, print->isi.notelp);
    print = print->chain;
    i++;
  }
}

void contact(int noantri, linkedlist ** kontak){
  data newcontact;
  char newnum[13];
  int choice;
  int pos;
  
  printf("\n=== BUKU KONTAK ===\n");
  printf("1. Tambah Kontak\n");
  printf("2. Lihat Kontak\n");
  printf("3. Kembali\n");
  printf("Pilihan: ");
  scanf("%d", &choice);
  getchar(); // Membersihkan buffer

  if(choice == 1) {
    printf("Masukkan nomor telepon: ");
    if (fgets(newnum, 13, stdin) != NULL) {
      newnum[strcspn(newnum, "\n")] = 0;
      if(!isnumvalid(newnum)) {
        setdata(noantri, newnum, 0, &newcontact); // Durasi 0 karena ini hanya kontak
        infront(kontak, newcontact); // Menambahkan ke depan list
        printf("Kontak berhasil ditambahkan!\n");
      }
    }
  }
  else if(choice == 2) {
    if(isempty(*kontak)) {
      printf("Buku kontak masih kosong!\n");
    } else {
      printf("\n=== DAFTAR KONTAK ===\n");
      printkontak(*kontak);
    }
  }
  else if(choice == 3) {
    return;
  }
  else {
    printf("Pilihan tidak valid!\n");
  }
}

void cekantrian(int noantri, linkedlist * antrian){
  printf("\nAntrian Booth Telepon:\n");
  printlist(antrian);
}

void dialall(linkedlist ** antrian, linkedlist ** dialer){
  if(isempty(*antrian)) {
    printf("Antrian masih kosong!\n");
    return;
  }

  printf("\n=== MEMULAI DIAL SEMUA ANTRIAN ===\n");
  linkedlist * temp = *antrian;
  linkedlist * temp2 = *dialer;
  
  while(temp != NULL) {
    printf("\nMemanggil nomor: %s\n", temp->isi.notelp);
    push(dialer, temp->isi);
    temp = temp->chain;
    printf("Nomor berhasil dipanggil!\n");
    pop(dialer);
    dequeue(antrian);
  }

  printf("\nSemua nomor telah dipanggil!\n");
}

#endif /* ifndef MACRO */
