#ifndef data_h
#define data_h

#include <stdio.h>
#include <string.h>

typedef struct telepon{
  int noantri;
  char notelp[13];
  int biaya;
} data;

// Setter
void setdata(int noantri, char * notelp, int durasi, data * out);

#endif // !kamus_h
