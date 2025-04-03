#ifndef type_h
#define type_h

#include <stdio.h>
#include <string.h>

typedef struct datapenerbangan {
  char tempat[5];
  char kodepenerbangan[8];
  char waktu[7];
  char info[22];
} data;

void setflight(char *newplace, char *flightcode, char *time, char *newinfo,
               data *stream) {
  strcpy((*stream).info, newinfo);
  strcpy((*stream).tempat, newplace);
  strcpy((*stream).waktu, time);
  strcpy((*stream).kodepenerbangan, flightcode);
}

void printdata(data stream) {
  printf("\n%s\t", stream.kodepenerbangan);
  printf("%s\t", stream.tempat);
  printf("%s\t", stream.waktu);
  printf("%s\t", stream.info);
}

void getstring(char *stream) {
  char temp[50];
  fgets(temp, sizeof(temp), stdin);
  temp[strcspn(temp, "\n")] = 0;
  strcpy(stream, temp);
}

void makesched(data *stream) {
  char jam[7];
  char place[5];
  char kode[8];
  char info[22];
  printf("Masukan Jam: ");
  getstring(jam);
  printf("Masukan Tujuan: ");
  getstring(place);
  printf("Masukan Kode Penerbangan: ");
  getstring(kode);
  printf("Masukan Info: ");
  getstring(info);
  setflight(place, kode, jam, info, stream);
}
#endif /* ifndef type_h */
