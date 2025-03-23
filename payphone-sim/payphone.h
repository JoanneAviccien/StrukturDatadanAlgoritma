#ifndef payphone_h
#define payphone_h

#include "lib-linklist/linkedlist.h"
#include "lib-linklist/types/queue.h"
#include "lib-linklist/types/stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isnumvalid(char *notelp);
void usebooth(int * noantri, linkedlist ** antrian);
void printkontak(linkedlist * list);
void contact(int noantri, linkedlist ** kontak);
void cekantrian(int noantri, linkedlist * antrian);
void dialall(linkedlist ** antrian, linkedlist ** dialer);

#endif // !telepon_h
