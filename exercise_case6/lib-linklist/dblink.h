#ifndef dblink_h
#define dblink_h

#include "../lib-government/type.h"
#include "singlylink.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
  struct dnode *prev;
  struct node *next;
  data isi;
} twolink;

void end();
void badend();

// Validator
bool isemptydb(twolink *list);

// Constructor
twolink *newdnode(data isinode);

// Operation
void dinrear(twolink **list, data stream);

void drmrear(twolink **list);

void travel(twolink *list, char gear, void (*func)(data));

#endif
