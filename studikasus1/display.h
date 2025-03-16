#ifndef display_h
#define display_h

#include <stdio.h>
#include <stdbool.h>
#include "linklist.h"


//Display
void separator(char *title);
void printmhs(mhsnode *head);
void countmhs(mhsnode *head);
void sortgrademhs(struct node * head);

#endif // !display_h
