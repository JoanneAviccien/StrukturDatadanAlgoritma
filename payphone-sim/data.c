#ifndef data_h
#define data_h

#include <string.h>
#include "data.h"

typedef struct telepon{
  int noantri;
  char notelp[13];
  int biaya;
} data;

void setdata(int noantri, char * notelp, int durasi, data * out){
  (*out).noantri = noantri;
  strcpy((*out).notelp, notelp);
  (*out).biaya = durasi * 500;
}

#endif
