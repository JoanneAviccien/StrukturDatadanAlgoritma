#ifndef type_h
#define type_h

#include <stdio.h>
#include <string.h>

typedef struct datapenerbangan {
  char tempat[3];
  char kodepenerbangan[6];
  char waktu[5];
  char info[];
} data;

void setflight(const char *newplace, const char *flightcode, const char *time,
               const char *newinfo, data *stream) {
  strcpy((*stream).info, newinfo);
  strcpy((*stream).tempat, newplace);
  strcpy((*stream).waktu, time);
  strcpy((*stream).kodepenerbangan, flightcode);
}

void printfdata(data stream) {
  printf("%s\t%s\t%s\t%s", stream.kodepenerbangan, stream.waktu, stream.tempat,
         stream.info);
}

#endif /* ifndef type_h */
