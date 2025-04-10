#ifndef dblink_h
#define dblink_h

#include "../type.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
  struct dnode *prev;
  struct dnode *next;
  data isi;
} twolink;

void end();
void badend();

// Validator
bool isempty(twolink *list);

// Constructor
twolink *newdnode(data isinode);

// Operation
void dinfront(twolink **list, data stream);
void dinrear(twolink **list, data stream);
void dinbetween(twolink **list, data stream, int pos);

void drmfront(twolink **list);
void drmrear(twolink **list);
void drmbetween(twolink **list, int pos);

void travel(twolink *list, char gear, void (*func)(data));

#endif
