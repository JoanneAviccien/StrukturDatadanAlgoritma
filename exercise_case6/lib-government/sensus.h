#ifndef sensus_h
#define sensus_h

#include "../userlib/lib-linklist/dblink.h"
#include "type.h"
#include <stdio.h>
#include <string.h>

void buatdata(twolink **kota);
void buatkota(twolink **kota);
void hapusdata(twolink **kota);
void showkota(twolink *provinsi);
void hapuskan(twolink **kota);
void demolish(twolink **provinsi);
void showsensus(twolink *datasensus);

#endif
