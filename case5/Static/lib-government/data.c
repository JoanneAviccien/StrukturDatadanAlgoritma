#ifndef data_h
#define data_h

#include <string.h>

typedef struct kota{
  char isi[50];
} data;

void setdata(char * fill, data * out){
  strcpy((*out).isi, fill);
}

#endif
