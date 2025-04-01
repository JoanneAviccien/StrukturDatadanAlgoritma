#ifndef sensus_h
#define sensus_h

#include <stdio.h>
#include <string.h>
#include "../lib-linklist/linkedlist.h"
#include "data.h"

void buatdata(linkedlist ** kota);
void buatkota(linkedlist ** kota);
void hapusdata(linkedlist ** kota);
void showkota(linkedlist * provinsi[5]);
void hapuskan(linkedlist ** kota);
void demolish(linkedlist * provinsi[5]);
void showsensus(linkedlist * datasensus);

#endif 
