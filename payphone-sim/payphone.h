#ifndef payphone_h
#define payphone_h

#include "lib-linklist/linkedlist.h"
#include "lib-linklist/types/queue.h"
#include "lib-linklist/types/stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isnumvalid(char *notelp);
void menu(int noantri, linkedlist ** antrian, linkedlist ** kontak);

#endif // !telepon_h
