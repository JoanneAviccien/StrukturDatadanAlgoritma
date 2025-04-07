#ifndef sensus_h
#define sensus_h

#include "../lib-linklist/dblink.h"
#include "type.h"
#include <stdio.h>
#include <string.h>

void buatdata(twolink **provinsi);
void buatkota(twolink **provinsi);
void showkota(twolink *provinsi);
void hapuskota(twolink **provinsi);
void demolish(twolink **provinsi);
void showsensus(twolink *datasensus);

#endif
